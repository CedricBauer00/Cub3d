/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:20:07 by cbauer            #+#    #+#             */
/*   Updated: 2025/09/03 15:44:38 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	get_player(t_configs *data, int i, int j, char c)
{
	static int	count = 0;

	count++;
	if (count > 1)
		return (printf("Error: Too many players!\n"), -1);
	data->map_info = gc_malloc(sizeof(t_map), MAP);
	if (!data->map_info)
		return (-1);
	data->map_info->y_pos = (float)i;
	data->map_info->x_pos = (float)j;
	data->map_info->plr_dir = c;
	data->map_info->hight = data->m_hight;
	data->map_info->width = data->m_width;
	data->map_info->map = data->map;
	return (0);
}

int	player(t_configs *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->m_hight)
	{
		j = 0;
		while (j < data->m_width)
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'W'
				|| data->map[i][j] == 'S' || data->map[i][j] == 'E')
			{
				if (get_player(data, i, j, data->map[i][j]) < 0)
					return (-1);
			}
			j++;
		}
		i++;
	}
	if (!data->map_info)
		return (printf("Error: No player found!\n"), -1);
	return (0);
}
