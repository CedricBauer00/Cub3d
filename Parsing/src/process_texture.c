/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:57:59 by cbauer            #+#    #+#             */
/*   Updated: 2025/08/27 11:07:33 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	process_texture(t_configs *data, char *path, char which)
{
	mlx_texture_t	*test;

	test = mlx_load_png(path);
	if (!test)
		return (printf("Error: mlx_load_png failed!\n"), -1);
	if (which == 'N')
		data->textures->no_text = test;
	if (which == 'S')
		data->textures->so_text = test;
	if (which == 'W')
		data->textures->we_text = test;
	if (which == 'E')
		data->textures->ea_text = test;
	// mlx_delete_texture(test); at the end of the program
	return (0);
}
