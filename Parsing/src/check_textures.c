/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:51:36 by cbauer            #+#    #+#             */
/*   Updated: 2025/08/05 13:19:49 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// char	

bool	foo(t_configs *data, char **txtrs)
{
	
}

int	check_textures(t_configs *data)
{
	int				i;
	mlx_texture_t	text;

	i = 0;
	data->textures = (t_textures *)malloc(sizeof(t_textures));
	if (!data->textures)
		return (printf("Error: Allocation failed!\n"), -1);
	// get_path(data->txtrs);
	while (i < 6)
	{
		foo(data, data->txtrs);
	}
	text = mlx_load_png()
}