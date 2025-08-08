/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:00:56 by cbauer            #+#    #+#             */
/*   Updated: 2025/08/08 14:57:48 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	per_line(t_configs *data, char *line, int i, int len)
{
	static int	flag = 0;

	if (flag == 1)
		return ;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '\n' || line[i] == '\0')
	{
		flag = 1;
		return ;
	}
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '\t')
			len += 4;
		else
			len++;
		i++;
	}
	data->m_hight++;
	if (data->m_width < len)
		data->m_width = len;
}

int	allocate_map(t_configs *data, int i)
{
	data->map = (char **)gc_malloc(sizeof(char *) * data->m_hight, MAP);
	if (!data->map)
		return (-1);
	while (i < data->m_hight)
	{
		data->map[i] = (char *)gc_malloc(sizeof(char) * data->m_width + 1, MAP);
		if (!data->map[i])
			return (-1);
		i++;
	}
	return (0);
}

int	init_map_helper(t_configs *data, int i, int j)
{
	int	fill_space;

	fill_space = 0;
	while (fill_space < 4)
	{
		data->map[i][j] = ' ';
		fill_space++;
		j++;
	}
	return (j);
}

void	init_map(t_configs *data, int i, int j, int l)
{
	while (i < data->m_hight)
	{
		j = 0;
		l = 0;
		while (j < data->m_width)
		{
			if (data->lines[i + 6][l] == '\n' || data->lines[i + 6][l] == '\0')
				data->map[i][j] = ' ';
			else if (data->lines[i + 6][l] == '\t')
				j = init_map_helper(data, i, j);
			else
				data->map[i][j] = data->lines[i + 6][l];
			if (data->lines[i + 6][l] != '\n' && data->lines[i + 6][l] != '\0')
				l++;
			j++;
		}
		data->map[i][j] = '\0';
		i++;
	}
}
// substitute tabs with spaces

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

int	create_map(t_configs *data)
{
	int	i;

	i = 6;
	while (data->lines[i])
	{
		per_line(data, data->lines[i], 0, 0);
		i++;
	}
	if (allocate_map(data, 0) < 0)
		return (-1);
	init_map(data, 0, 0, 0);
	if (check_map(data, data->map) < 0)
		return (-1);
	if (player(data) < 0)
		return (-1);
	if (set_up_fl(data) < 0)
		return (-1);
	return (0);
}
