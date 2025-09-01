/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:58:16 by cbauer            #+#    #+#             */
/*   Updated: 2025/09/01 12:25:24 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse_button(mouse_key_t button, action_t action,
	modifier_key_t modifier, void *ptr)
{
	t_game	*g;

	(void)modifier;
	g = (t_game *)ptr;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
		g->show = 8;
	
}