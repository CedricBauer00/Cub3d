/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:50:40 by cbauer            #+#    #+#             */
/*   Updated: 2025/09/03 13:03:52 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_pngs(t_game *g)
{
	mlx_texture_t	*png;

	png = mlx_load_png("animations/weapon1A.png");
	if (!png)
		return (-1);
	g->gun_anim->gun_img = mlx_texture_to_image(g->mlx, png);
	if (!g->gun_anim->gun_img)
	{
		mlx_delete_texture(png);
		return (-1);
	}
	mlx_delete_texture(png);
	png = mlx_load_png("animations/weapon1B.png");
	if (!png)
		return (-1);
	g->gun_anim->fire_gun = mlx_texture_to_image(g->mlx, png);
	if (!g->gun_anim->fire_gun)
	{
		mlx_delete_texture(png);
		return (-1);
	}
	mlx_delete_texture(png);
	return (0);
}

int	init_animation(t_game *g)
{
	int				x;
	int				y;

	g->show = 0;
	g->timer = 0;
	g->gun_anim = gc_malloc(sizeof(t_aniamtion), EXEC);
	if (!g->gun_anim)
		return (-1);
	if (load_pngs(g) < 0)
		return (-1);
	g->gun_anim->gun_offset = 10;
	g->gun_anim->gun_movement = false;
	x = (g->mlx->width - g->gun_anim->gun_img->width) / 2
		+ (g->mlx->width - g->gun_anim->gun_img->width) / 4
		- (g->mlx->width - g->gun_anim->gun_img->width) / 8;
	y = (g->mlx->height - g->gun_anim->gun_img->height);
	mlx_resize_image(g->gun_anim->gun_img, 200, 200);
	mlx_image_to_window(g->mlx, g->gun_anim->gun_img, x, y);
	mlx_resize_image(g->gun_anim->fire_gun, 200, 200);
	mlx_image_to_window(g->mlx, g->gun_anim->fire_gun, x, y);
	g->gun_anim->fire_gun->instances[0].enabled = false;
	return (0);
}

void	show_gun_fire(t_game *g)
{
	if (g->show > 0)
	{
		if (g->show == 8)
		{
			g->gun_anim->gun_img->instances[0].enabled = false;
			g->gun_anim->fire_gun->instances[0].enabled = true;
		}
		g->show--;
	}
	else
	{
		g->gun_anim->gun_img->instances[0].enabled = true;
		g->gun_anim->fire_gun->instances[0].enabled = false;
	}
}

void	move_gun(t_game *g)
{
	show_gun_fire(g);
	if (!g->move && !g->std)
	{
		g->timer = 0;
		g->gun_anim->gun_movement = false;
		g->gun_anim->gun_img->instances[0].y = g->mlx->height
			- g->gun_anim->gun_img->height;
		g->std = true;
		return ;
	}
	else if (!g->move)
		return ;
	g->std = false;
	g->timer = (g->timer + 1) % 7;
	if (g->timer != 0)
		return ;
	g->gun_anim->gun_movement = !g->gun_anim->gun_movement;
	if (g->gun_anim->gun_movement == true)
		g->gun_anim->gun_img->instances[0].y = g->mlx->height
			- g->gun_anim->gun_img->height + g->gun_anim->gun_offset;
	else
		g->gun_anim->gun_img->instances[0].y = g->mlx->height
			- g->gun_anim->gun_img->height;
}
