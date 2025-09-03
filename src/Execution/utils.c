/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:09:42 by batuhan           #+#    #+#             */
/*   Updated: 2025/09/03 15:01:28 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	delete_textures(t_game *g)
{
	if (g->tex->no)
		mlx_delete_texture(g->tex->no);
	if (g->tex->so)
		mlx_delete_texture(g->tex->so);
	if (g->tex->we)
		mlx_delete_texture(g->tex->we);
	if (g->tex->ea)
		mlx_delete_texture(g->tex->ea);
	if (g->tex->door)
		mlx_delete_texture(g->tex->door);
	if (g->gun_anim->fire_gun)
		mlx_delete_image(g->mlx, g->gun_anim->fire_gun);
	if (g->gun_anim->gun_img)
		mlx_delete_image(g->mlx, g->gun_anim->gun_img);
}

// void	delete_textures(t_game *g)
// {
// 	mlx_delete_texture(g->tex->no);
// 	mlx_delete_texture(g->tex->so);
// 	mlx_delete_texture(g->tex->we);
// 	mlx_delete_texture(g->tex->ea);
// 	mlx_delete_texture(g->tex->door);
// 	mlx_delete_image(g->mlx, g->gun_anim->fire_gun);
// 	mlx_delete_image(g->mlx, g->gun_anim->gun_img);
// }

double	normalised_angle(double angle)
{
	if (angle < 0)
		angle += 2.0 * PI;
	if (angle >= 2.0 * PI)
		angle -= 2.0 * PI;
	return (angle);
}

void	initialize(t_map *maps, t_game *game)
{
	game->map = maps->map;
	game->mwidth = maps->width;
	game->mheight = maps->hight;
	if (maps->plr_dir == 'N')
		game->player->angle = PI / 2;
	if (maps->plr_dir == 'S')
		game->player->angle = PI / 2 + PI;
	if (maps->plr_dir == 'W')
		game->player->angle = PI;
	if (maps->plr_dir == 'E')
		game->player->angle = PI * PI;
	game->player->x = maps->x_pos * TS + 32;
	game->player->y = maps->y_pos * TS + 32;
	game->player->dir_x = cos(game->player->angle);
	game->player->dir_y = sin(game->player->angle);
	game->player->plane_x = -game->player->dir_y * 0.66;
	game->player->plane_y = game->player->dir_x * 0.66;
	game->a = false;
	game->s = false;
	game->d = false;
	game->w = false;
	game->l = false;
	game->r = false;
	// game->move = false;
	// game->std = false;
}

void	rotate_right(t_game *game)
{
	game->player->angle -= SPEED;
	if (game->player->angle < 0)
		game->player->angle += 2 * PI;
}

void	rotate_left(t_game *game)
{
	game->player->angle += SPEED;
	if (game->player->angle > 2 * PI)
		game->player->angle -= 2 * PI;
}
