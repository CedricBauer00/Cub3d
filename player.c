/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 12:33:53 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/11 17:19:37 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	delete_image(mlx_image_t *image)
{
	ft_memset(image->pixels, 0, image->width * image->height * sizeof(uint32_t));
}

static void	draw_player_helper(t_game *game, mlx_image_t *img)
{
	int	i;
	int	j;
	int	d_x;
	int	d_y;

	i = 0;
	d_x = game->player->x;
	d_y = game->player->y;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			mlx_put_pixel(img, d_x + i, d_y + j, 0xFFFF00FF);
			j++;
		}
		i++;
	}
}

void	draw_player_ex(t_game *game, mlx_image_t *image)
{
	int i;
    int d_x;
    int d_y;
	int	p_x;
	int	p_y;

    i = 0;
    d_x = game->player->x;
    d_y = game->player->y;
	delete_image(image);
	draw_ray(game, game->player, image, 0);
	while (i < 20)
	{
		p_x = d_x + 4 + (int)round(cos(game->player->angle) * i);
		p_y = d_y + 4 - (int)round(sin(game->player->angle) * i);
		mlx_put_pixel(image, p_x, p_y, 0xFFFF00FF);
		i++;
	}
	draw_player_helper(game, image);
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

void	ray_initializer(t_player *p)
{
	p->rayDirX = cos(p->angle);
	p->rayDirY = -sin(p->angle);
	if (p->rayDirX == 0.0)
		p->deltaDistX = 1e30;
	else
		p->deltaDistX = fabs(1.0 / p->rayDirX);
	if (p->rayDirY == 0.0)
		p->deltaDistY = 1e30;
	else
		p->deltaDistY = fabs(1.0 / p->rayDirY);
	p->posX = (p->x + 4) / (double)64;
	p->posY = (p->y + 4) / (double)64;
	p->mapX = (int)p->posX;
	p->mapY = (int)p->posY;
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

void	draw_ray(t_game *game, t_player *p, mlx_image_t *image, int check)
{
	int		hx;
	int		hy;
	double	wallDist;
	double	hitX;
	double	hitY;
	
	ray_initializer(p);
	check = ray_loop(game, p);
	if (check == -1)
		return ;
	if (check == 0)
		wallDist = (p->mapX - p->posX + (1 - p->stepX) / 2.0) / p->rayDirX;
	else
		wallDist = (p->mapY - p->posY + (1 - p->stepY) / 2.0) / p->rayDirY;
	hitX = p->posX + p->rayDirX * wallDist;
	hitY = p->posY + p->rayDirY * wallDist;
	hx = (int)round(hitX * 64);
	hy = (int)round(hitY * 64);
	printf("hx = %d, hy = %d\n", hx / 64, hy / 64);
	draw_ray_helper(game, image, hx, hy);
}
