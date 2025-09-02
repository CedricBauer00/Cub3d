/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:02:57 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/26 15:07:12 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	Here we have the first part of the calculations made for the ray.
	we have the ray as a straight line and since we know the tile size and 
	where it's pointed to, using cos and sin functions we can determine the
	movements of our character.(sin is set as minus because it grows downwards)

	Then we use the fabs function to make the number we want to assign positive
	if it's negative.
	We need to calculate delta distances because depending on
	the angle of the ray, the amount of movement in the x and y directions changes
	and if it's 0 we set the deltaDirX/Y to 1e30(infinity) because otherwise we
	would try to divide a number by 0 which is not possible.

	We add 4 to the coordinants because of how i draw stuff but i will be changing
	that.
	Then we divide them by 64 because for the moment our tile size is 64.
	For example the map is 512 x 512 long because it was built pixel by pixel,
	if x is 134 we know that x is actually 2, which helps us see where we are on
	the map by using something like map[y][x].

	the if statements down at the bottom in the ray_initializer2 function are for
	the directions we need to follow.
	sideDistX/Y are there to determine how much we need to move in the y and x axis.
*/

void	ray_initializer(t_player *p, double angle)
{
	p->ray_dir_x = cos(angle);
	p->ray_dir_y = -sin(angle);
	if (p->ray_dir_x == 0.0)
		p->delta_dist_x = 1e30;
	else
		p->delta_dist_x = fabs(1.0 / p->ray_dir_x);
	if (p->ray_dir_y == 0.0)
		p->delta_dist_y = 1e30;
	else
		p->delta_dist_y = fabs(1.0 / p->ray_dir_y);
	p->pos_x = (p->x) / (double)TS;
	p->pos_y = (p->y) / (double)TS;
	p->map_x = (int)p->pos_x;
	p->map_y = (int)p->pos_y;
	ray_initializer_2(p);
}

void	ray_initializer_2(t_player *p)
{
	if (p->ray_dir_x > 0)
	{
		p->step_x = 1;
		p->side_dist_x = (p->map_x + 1 - p->pos_x) * p->delta_dist_x;
	}
	else
	{
		p->step_x = -1;
		p->side_dist_x = (p->pos_x - p->map_x) * p->delta_dist_x;
	}
	if (p->ray_dir_y > 0)
	{
		p->step_y = 1;
		p->side_dist_y = (p->map_y + 1 - p->pos_y) * p->delta_dist_y;
	}
	else
	{
		p->step_y = -1;
		p->side_dist_y = (p->pos_y - p->map_y) * p->delta_dist_y;
	}
}

void	draw_ray_init(t_player *p, t_ray *r, double angle, int check)
{
	r->angle_diff = angle - p->angle;
	r->angle_diff = normalised_angle(r->angle_diff);
	if (r->angle_diff > PI)
		r->angle_diff -= 2.0 * PI;
	if (check == 0)
		r->raw_dist = (p->map_x - p->pos_x
				+ (1.0 - p->step_x) * 0.5) / p->ray_dir_x;
	else
		r->raw_dist = (p->map_y - p->pos_y
				+ (1.0 - p->step_y) * 0.5) / p->ray_dir_y;
	r->wall_dist = r->raw_dist * cos(r->angle_diff);
	if (r->wall_dist < 1e-6)
		r->wall_dist = 1e-6;
}
