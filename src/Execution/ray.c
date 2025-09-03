/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:35:31 by batuhan           #+#    #+#             */
/*   Updated: 2025/09/03 14:34:21 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		if (game->map[p->map_y][p->map_x] == '1'
				|| game->map[p->map_y][p->map_x] == 'D')
			break ;
	}
	return (side);
}

void	draw_ray(t_game *game, int check, double angle)
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
}

void	draw_multiple_ray(t_game *game)
{
	double	fov;
	double	start;
	double	step;
	int		i;

	fov = 60.0 * PI / 180;
	start = game->player->angle - fov * 0.5;
	step = fov / (double)RAY_N;
	i = 0;
	while (i < RAY_N)
	{
		game->ray_i = i;
		draw_ray(game, 0, start + step * i);
		i++;
	}
}
