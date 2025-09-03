/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:02:57 by batuhan           #+#    #+#             */
/*   Updated: 2025/09/03 14:34:26 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
