/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:52:28 by cbauer            #+#    #+#             */
/*   Updated: 2025/09/02 11:23:16 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_doors(t_configs *data, char **map, int i, int j)
{
	if (i - 1 >= 0 && map[i - 1][j] == '1')
	{
		if (i + 1 < data->m_hight && map[i + 1][j] == '1')
			return (0);
	}
	if (j - 1 >= 0 && map[i][j - 1] == '1')
	{
		if (j + 1 < data->m_width && map[i][j + 1] == '1')
			return (0);
	}
	return (printf("Error: Door is invalid!\n"), -1);
}
