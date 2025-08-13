/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:35:31 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/13 16:57:39 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	normalised_angle(double angle)
{
	if (angle < 0)
		angle += 2.0 * PI;
	if (angle >= 2.0 * PI)
		angle -= 2.0 * PI;
	return (angle);
}

void	draw_ray_helper(t_game *game, mlx_image_t *image, int hx, int hy)
{
	int	i = 0;
	double	xx;
	double	yy;
	int	x = game->player->x + 4;
	int	y = game->player->y + 4;
	int	steps = (int)fmax(abs(hx - x), abs(hy - y));
	double	incx;
	double	incy;

	if (steps < 1)
		steps = 1;
	incx = (hx - x) / (double)steps;
	incy = (hy - y) / (double)steps;
	xx = x;
	yy = y;
	while (i <= steps)
	{
		mlx_put_pixel(image, (int)round(xx), (int)round(yy), 0xFF0000FF);
		xx += incx;
		yy += incy;
		i++;
	}
}
/*
	Here we have the first part of the calculations made for the ray.
	we have the ray as a straight line and since we know the tile size and 
	where it's pointed to, using cos and sin functions we can determine the
	movements of our character.(sin is set as minus because it grows downwards)

	Then we use the fabs function to make the number we want to assign positive
	if it's negative.
	We need to calculate delta distances because depending on
	the angle of the ray, the amount of movement in the x and y directions changes
	and if it's 0 we set the deltaDirX/Y to 1e30(infinity) because otherwise we would try to
	divide a number by 0 which is not possible.

	We add 4 to the coordinants because of how i draw stuff but i will be changing that.
	Then we divide them by 64 because for the moment our tile size is 64.
	For example the map is 512 x 512 long because it was built pixel by pixel,
	if x is 134 we know that x is actually 2, which helps us see where we are on the map by using something like map[y][x].

	the if statements down at the bottom are for the directions we need to follow.
	sideDistX/Y are there to determine how much we need to move in the y and x axis.
*/

void	ray_initializer(t_player *p, double angle)
{
	p->rayDirX = cos(angle);
	p->rayDirY = -sin(angle);
	if (p->rayDirX == 0.0)
		p->deltaDistX = 1e30;
	else
		p->deltaDistX = fabs(1.0 / p->rayDirX);
	if (p->rayDirY == 0.0)
		p->deltaDistY = 1e30;
	else
		p->deltaDistY = fabs(1.0 / p->rayDirY);
	p->posX = (p->x) / (double)TS;
	p->posY = (p->y) / (double)TS;
	p->mapX = (int)p->posX;
	p->mapY = (int)p->posY;
    ray_initializer_2(p);
}

void    ray_initializer_2(t_player *p)
{
    if (p->rayDirX > 0)
	{
		p->stepX = 1;
		p->sideDistX = (p->mapX + 1 - p->posX) * p->deltaDistX;
	}
	else
	{
		p->stepX = -1;
		p->sideDistX = (p->posX - p->mapX) * p->deltaDistX;
	}
	if (p->rayDirY > 0)
	{
		p->stepY = 1;
		p->sideDistY = (p->mapY + 1 - p->posY) * p->deltaDistY;
	}
	else
	{
		p->stepY = -1;
		p->sideDistY = (p->posY - p->mapY) * p->deltaDistY;
	}
}

/*
	Here we keep moving till we hit a wall. Depending on which variable is behind we make movement.
	if x is more than y we increase y and the other way around.

	the side variable determins weather x or y was the last one to march forwards.

	mapX is where we are currently at the map and stepX is there to put us into the right direction.
	so if stepX is -1 it means we can only walk backwards in the x axis.

	Then at the bottom we have the checks for the loop. if the numbers are bigger than the map size we
	stop the loop and return a value depending on which one was the last one to move.
*/

int	ray_loop(t_game *game, t_player *p)
{
	int	side;

	side = 3;
	while (1)
	{
		if (p->sideDistX < p->sideDistY)
		{
			p->mapX += p->stepX;
			p->sideDistX += p->deltaDistX;
			side = 0;
		}
		else
		{
			p->mapY += p->stepY;
			p->sideDistY += p->deltaDistY;
			side = 1;
		}
		if (p->mapX < 0 || p->mapY < 0 || p->mapX >= 8 || p->mapY >= 8)
			return (-1);
		if (game->map[p->mapY][p->mapX] == 1)
			break ;
	}
	return (side);
}

void	draw_vertical(int drawS, int drawE, int check, mlx_image_t *img, int hx, int hy, int asd)
{
	int	i;
	int	j;

	i = drawS;
	j = WIDTH - asd;
	while (i < drawE)
	{
		if (check == 0)
			mlx_put_pixel(img, j, i, 0x008000FF);
		else
			mlx_put_pixel(img, j, i, 0x90EE90FF);
		i++;
	}
	// printf("e = %d, s = %d\n", drawE, drawS);
}

t_ray	draw_ray(t_game *game, t_player *p, mlx_image_t *image, int check, double angle, int i)
{
	int		hx;
	int		hy;
	double	wallDist;
	double	hitX;
	double	hitY;
	int		lineH;
	int		drawS;
	int		drawE;
	double	angleDiff;
	double	rawDist;
	double	perpDist;
	t_ray	ray;
	
	// printf("here!\n");
	ray_initializer(p, angle);
	check = ray_loop(game, p);
	if (check == -1)
		return (ray);
	angleDiff = angle - p->angle;
	// angleDiff = normalised_angle(angleDiff);
	if (check == 0)
		perpDist = (p->mapX - p->posX + (1.0 - p->stepX) * 0.5) / p->rayDirX;
	else
		perpDist = (p->mapY - p->posY + (1.0 - p->stepY) * 0.5) / p->rayDirY;
	perpDist *= cos(angleDiff);
	// perpDist = fabs(perpDist);
	if (perpDist < 1e-6)
		perpDist = 1e-6;
	// if (check==0) printf("Xside  dir=(%.3f,%.3f) stepX=%d\n", p->rayDirX, p->rayDirY, p->stepX);
	// else          printf("Yside  dir=(%.3f,%.3f) stepY=%d\n", p->rayDirX, p->rayDirY, p->stepY);
	// if (check == 0)
	// 	wallDist = (p->sideDistX - p->deltaDistX);
	// else
	// 	wallDist = (p->sideDistY - p->deltaDistY);
	// wallDist *= cos(angleDiff);
	hitX = p->posX + p->rayDirX * perpDist;
	hitY = p->posY + p->rayDirY * perpDist;
	hx = (int)round(hitX * TS);
	hy = (int)round(hitY * TS);
	ray.hit = 1;
	ray.side = check;
	// ray.wall_dist = perpDist;
	ray.hx = hx;
	ray.hy = hy;
	lineH = (int)(HEIGHT / perpDist);
	drawS = -lineH / 2 + HEIGHT / 2;
	if (drawS < 0)
		drawS = 0;
	drawE = lineH / 2 + HEIGHT / 2;
	if (drawE >= HEIGHT)
		drawE = HEIGHT - 1;
	// printf("here!2\n");
	draw_vertical(drawS, drawE, check, image, hx, hy, i);
	// printf("here!3\n");
	return (ray);
}

void	draw_multiple_ray(t_game *game, mlx_image_t *img)
{
	double	fov;
	double	start;
	double	step;
	int		i;
	t_ray	ray;

	fov = 90.0 * PI / 180;
	start = game->player->angle - fov * 0.5;
	step = fov / (double)(RAY_N - 1);
	i = 0;
	while (i < RAY_N)
	{
		ray = draw_ray(game, game->player, img, 0, start + step * i, i);
		if (ray.hit)
			draw_ray_helper(game, img, ray.hx, ray.hy);
		i++;
	}
}
