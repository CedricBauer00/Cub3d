/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:55:06 by cbauer            #+#    #+#             */
/*   Updated: 2025/08/11 15:55:30 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_map(t_configs *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->m_hight)
	{
		j = 0;
		while (j < data->m_width)
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N'
				&& map[i][j] != 'S' && map[i][j] != 'W' && map[i][j] != 'E'
				&& map[i][j] != 'D' && map[i][j] != ' ')
				return (printf("Error: Invalid character in map!\n"), -1);
			if (map[i][j] == 'D')
			{
				if (check_doors(data, map, i, j) < 0)
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
