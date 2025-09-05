/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:57:59 by cbauer            #+#    #+#             */
/*   Updated: 2025/09/05 07:09:57 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"


void	del_txts(t_configs *data)
{
	if (data->textures->count > 0)
		mlx_delete_texture(data->textures->no_text);
	if (data->textures->count > 1)
		mlx_delete_texture(data->textures->so_text);
	if (data->textures->count > 2)
		mlx_delete_texture(data->textures->we_text);
	if (data->textures->count > 3)
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
	data->textures->count++;
	return (0);
}
