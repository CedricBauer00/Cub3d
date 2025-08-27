/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:35:31 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/27 10:21:29 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	this functions basically draws the rays. i will work on it more because
	it doesn't fit the 42 norm at the moment.
*/

void	draw_ray_helper(t_game *game, mlx_image_t *image, int hx, int hy)
{
	int	i = 0;
	double	xx;
	double	yy;
	int	x = game->player->x;
	int	y = game->player->y;
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
	Here we keep moving till we hit a wall. Depending on which variable is behind
	we make movement. if x is more than y we increase y and the other way around.

	the side variable determins weather x or y was the last one to march forwards
	and also helps us when we draw the walls
	cus it shows us which side of the wall we hit..

	mapX is where we are currently at the map and stepX is there to put us into
	the right direction.
	so if stepX is -1 it means we can only walk backwards in the x axis.

	Then at the bottom we have the checks for the loop. if the numbers are bigger
	than the map size we
	stop the loop and return a value depending on which one was the last one to move
*/

int	ray_loop(t_game *game, t_player *p)
{
	int	side;

	side = 3;
	while (1)
	{
		if (p->side_dist_x < p->side_dist_y)
		{
			p->map_x += p->step_x;
			p->side_dist_x += p->delta_dist_x;
			side = 0;
		}
		else
		{
			p->map_y += p->step_y;
			p->side_dist_y += p->delta_dist_y;
			side = 1;
		}
		if (p->map_x < 0 || p->map_y < 0 || p->map_x >= game->mwidth
			|| p->map_y >= game->mheight)
			break ;
		if (game->map[p->map_y][p->map_x] == '1')
			break ;
	}
	return (side);
}

/*
	Here we draw the 3d image. drawS is the beginning of the wall and
	drawE is the end.
	Check is the side of the wall that we hit.
	ray_i is the index of the array from the draw_multiple_ray function.
	and we substract it from the width cus otherwise the image feels inverted.
	it can be fixed by changing the rotate left and right functions but when we
	add the 2d, it's inverted in the 2d map instead.
	
	we first draw till the first wall to have a sky. then depending on the side of
	the wall the ray hits we draw the wall.
*/

t_ray	draw_ray(t_game *game, int check, double angle)
{
	t_ray		r;
	t_player	*p;

	p = game->player;
	ray_initializer(p, angle);
	check = ray_loop(game, p);
	draw_ray_init(p, &r, angle, check);
	r.hit_x = p->pos_x + p->ray_dir_x * r.raw_dist;
	r.hit_y = p->pos_y + p->ray_dir_y * r.raw_dist;
	r.hx = (int)round(r.hit_x * TS);
	r.hy = (int)round(r.hit_y * TS);
	r.hit = 1;
	r.side = check;
	r.line_h = (int)(HEIGHT / r.wall_dist);
	r.draw_s = -r.line_h / 2 + HEIGHT / 2;
	if (r.draw_s < 0)
		r.draw_s = 0;
	r.draw_e = r.line_h / 2 + HEIGHT / 2;
	if (r.draw_e >= HEIGHT)
		r.draw_e = HEIGHT - 1;
	draw_vertical(game, r, check, game->ray_i);
	return (r);
}

/*
	so we have a few variables here. fov is the field of view. we have to do the
	calculations below because we need to convert the fov to radians.
	the reason why it's 60 degrees is that it looks nicer? idk, i saw others do
	the same. 

	the start variable is being calculated that way because if we would just add
	the fov to the game we would have the fov start from the middle of the
	character and expand to the right or left depending on how the calculation is
	being made in the later functions. but when we substract the half of the 
	fov in radians, it's starts from the left side and ends at the right side.
	if you need more explanation about this variable i can do some drawing in person
	to be able to explain it better.

	the last variable is called step. the reason why we have this variable is to
	calculate how often the rays will be casted. let's say fov is 50 a
	- converting the colours.nd we have
	5 rays. this means we will be putting a ray every 10 degrees.

	in draw_ray function there is a calculation made, which is start + step * i.
	normally i'd write the idea by myself but for this moment i'm too lazy to work
	with the small and detailed numbers so imma let the ai give an example. 
	Ray 0: 60° + (0.0586° × 0) = 60° (leftmost ray)
	Ray 512: 60° + (0.0586° × 512) = 90° (center ray - straight ahead)
	Ray 1023: 60° + (0.0586° × 1023) = 120° (rightmost ray)

	the last thing here is draw_ray_Helper function. we use that when we want to
	draw the rays on the 2d map, which will be used when working on
	the minimap most probably.
*/

void	draw_multiple_ray(t_game *game)
{
	double	fov;
	double	start;
	double	step;
	int		i;
	t_ray	ray;

	fov = 60.0 * PI / 180;
	start = game->player->angle - fov * 0.5;
	step = fov / (double)RAY_N;
	i = 0;
	while (i < RAY_N)
	{
		game->ray_i = i;
		ray = draw_ray(game, 0, start + step * i);
		i++;
	}
}
