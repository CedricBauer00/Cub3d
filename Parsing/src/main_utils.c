/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:46:07 by cbauer            #+#    #+#             */
/*   Updated: 2025/08/11 13:17:09 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

int	check_duplicate(char **lines)
{
	int		i;
	t_seen	flags;

	i = -1;
	if (set_flags(&flags) < 0)
		return (-1);
	while (++i < 6)
	{
		if (ft_strncmp(lines[i], "NO ", 3) == 0)
			flags.no++;
		if (ft_strncmp(lines[i], "SO ", 3) == 0)
			flags.so++;
		if (ft_strncmp(lines[i], "WE ", 3) == 0)
			flags.we++;
		if (ft_strncmp(lines[i], "EA ", 3) == 0)
			flags.ea++;
		if (ft_strncmp(lines[i], "F ", 2) == 0)
			flags.f++;
		if (ft_strncmp(lines[i], "C ", 2) == 0)
			flags.c++;
	}
	if (flags.no != 1 || flags.so != 1 || flags.we != 1 || flags.ea != 1
		|| flags.f != 1 || flags.c != 1)
		return (printf("Error: Input error: Duplicates/Missing lines!\n"), -1);
	return (0);
}

bool	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}

int	seperate(t_configs *data)
{
	data->txtrs = (char **)gc_malloc(sizeof(char *) * 7, PARS);
	if (!data->txtrs)
		return (-1);
	if (init_txtrs(data) < 0)
		return (-1);
	if (check_duplicate(data->txtrs) < 0)
		return (-1);
	if (check_textures(data, -1, NULL, 0) < 0)
		return (-1);
	if (create_map(data) < 0)
		return (-1);
	return (0);
}
