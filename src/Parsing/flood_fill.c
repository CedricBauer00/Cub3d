/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:09:33 by cbauer            #+#    #+#             */
/*   Updated: 2025/09/03 12:14:41 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	flood_fill(t_configs *data, int y, int x, char **map)
{
	if (x < 0 || y < 0 || y >= data->m_hight || x >= data->m_width
		|| map[y][x] == ' ')
		return (-1);
	if (map[y][x] == '1' || map[y][x] == 'F')
		return (0);
	map[y][x] = 'F';
	if (flood_fill(data, y, x + 1, map) < 0)
		return (-1);
	if (flood_fill(data, y, x - 1, map) < 0)
		return (-1);
	if (flood_fill(data, y + 1, x, map) < 0)
		return (-1);
	if (flood_fill(data, y - 1, x, map) < 0)
		return (-1);
	return (0);
}

int	set_up_fl(t_configs *data)
{
	int		i;
	char	**subst_map;

	i = 0;
	subst_map = gc_malloc(sizeof(char *) * data->m_hight, PARS);
	if (!subst_map)
		return (-1);
	while (i < data->m_hight)
	{
		subst_map[i] = gc_strdup(data->map[i], PARS);
		if (!subst_map[i])
			return (-1);
		i++;
	}
	if (flood_fill(data, data->map_info->y_pos,
			data->map_info->x_pos, subst_map) < 0)
		return (printf("Error: Map wall is invalid!\n"), -1);
	return (0);
}
