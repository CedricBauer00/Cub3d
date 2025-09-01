/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:46:14 by cbauer            #+#    #+#             */
/*   Updated: 2025/08/28 13:14:05 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_animation(t_game *g)
{
	xpm_t	*xpm;

	g->gun_anim = gc_malloc(sizeof(t_aniamtion), EXEC);
	if (!g->gun_anim)
		return (-1);
	xpm = mlx_load_xpm42("animations/weapon1.pm");
	if (!xpm)
		return (-1);
	g->gun_anim->gun_text = mlx_texture_to_image(g->mlx, &xpm->texture);
	if (!g->gun_anim->gun_text)
	{
		mlx_delete_xpm42(xpm);
		return (-1);
	}
	mlx_delete_xpm42(xpm);
	g->gun_anim->gun_offset = 0;
	g->gun_anim->gun_movement = false;
	return (0);
}

void	move_gun(t_game *g)
{
	if (g->gun_anim->gun_movement)
	{
		g->gun_anim->gun_offset += 1; //up/down movement
		if (g->gun_anim->gun_offset > 5)
		{
			g->gun_anim->gun_offset = -5;
			g->gun_anim->gun_movement = false; // stop movement
		}
	}
}

void	draw_gun(t_game *g)
{
	mlx_image_t		*gun_image;
	int				gun_x;
	int				gun_y;

	gun_x = WIDTH / 2 - g->gun_anim->gun_text->width / 2;
	gun_y = HEIGHT - g->gun_anim->gun_text->height + g->gun_anim->gun_offset;
	gun_image = mlx_texture_to_image(g->mlx, g->gun_anim->gun_text);
	mlx_image_to_window(g->mlx, g->gun_anim->gun_text, gun_x, gun_y);
}
