/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:57:59 by cbauer            #+#    #+#             */
/*   Updated: 2025/09/04 09:05:20 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"


void	del_txts(t_configs *data)
{
	if (data->textures->no_text)
		mlx_delete_texture(data->textures->no_text);
	if (data->textures->so_text)
		mlx_delete_texture(data->textures->so_text);
	if (data->textures->we_text)
		mlx_delete_texture(data->textures->we_text);
	if (data->textures->ea_text)
		mlx_delete_texture(data->textures->ea_text);
}

int	process_texture(t_configs *data, char *path, char which)
{
	mlx_texture_t	*test;

	test = mlx_load_png(path);
	if (!test)
		return (-1);
	if (which == 'N')
		data->textures->no_text = test;
	if (which == 'S')
		data->textures->so_text = test;
	if (which == 'W')
		data->textures->we_text = test;
	if (which == 'E')
		data->textures->ea_text = test;
	return (0);
}
