/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:46:14 by cbauer            #+#    #+#             */
/*   Updated: 2025/08/27 13:19:18 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_animation(t_game *g)
{
	g->gun_anim = gc_malloc(sizeof(t_aniamtion), EXEC);
	if (!g->gun_anim)
		return (-1);
	g->gun_anim->gun_text = mlx_load_xpm42("animations/weapon1.pm");
	g->gun_anim->gun_offset = 0;
	g->gun_anim->gun_movement = false;
}

void	move_gun(t_game *g)
{
	if (g->gun_anim->gun_movement)
	{
		g->gun_anim->gun_offset += 1; //up/down movement
		if (g->gun_anim->gun_offset)
		{
			g->gun_anim->gun_offset = -5;
			g->gun_anim->gun_movement = false; // stop movement
		}
	}
}

void	draw_gun(t_game *g)
{
	int	gun_x = WIDTH / 2 - g->gun_anim->gun_text->width / 2;
	int	gun_y = HEIGHT - g->gun_anim->gun_text->height + g->gun_anim->gun_offset;
	mlx_texture_t	*gun_image = mlx_texture_to_image(g->mlx, g->gun_anim->gun_text);
	mlx_image_to_window(g->mlx, gun_image, gun_x, gun_y);
}
