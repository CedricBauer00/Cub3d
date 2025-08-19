/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:46:07 by cbauer            #+#    #+#             */
/*   Updated: 2025/08/19 09:37:14 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

bool	check_empty_line(char *line) //checks if a line in the map.cub file is empty - so it can be skipped by returning false
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\n')
		return (false);
	return (true);
}

void	init_data(t_configs	*data)
{
	data->lines = NULL;
	data->lcount = 0;
	data->txtrs = NULL;
	data->textures = NULL;
	data->where_color_is = 0;
	data->m_hight = 0;
	data->m_width = 0;
	data->map = NULL;
	data->map_info = NULL;
}

int	correct_name(char *argv1)
{
	int	i;

	i = ft_strlen(argv1);
	if (i <= 4)
		return (printf("Error: Map name too short!\n"), -1);
	i -= 4;
	if (ft_strncmp(argv1 + i, ".cub", 4) != 0)
	{
		printf("Error: Incorrect naming! Try a file ending with .cub\n");
		return (-1);
	}
	return (0);
}

int	set_flags(t_seen *flags)
{
	flags->no = 0;
	flags->so = 0;
	flags->we = 0;
	flags->ea = 0;
	flags->f = 0;
	flags->c = 0;
	return (0);
}

bool	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}
