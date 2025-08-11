/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:51:36 by cbauer            #+#    #+#             */
/*   Updated: 2025/08/11 15:57:59 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	*get_path(char *str)
{
	if (str[0] == 'N' || str[0] == 'S' || str[0] == 'W' || str[0] == 'E')
		return (gc_substr(str, 3, ft_strlen(str) - 3, TEXT));
	else
		return (gc_substr(str, 2, ft_strlen(str) - 2, TEXT));
}

int	str_isdigit(char *str)
{
	int	i;
	int	num;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	if (i > 3)
		return (printf("Error: Out of int range!\n"), -1);
	num = ft_atoi(str);
	if (num < 0 || num > 255)
		return (printf("Error: Color code invalid!\n"), -1);
	return (0);
}

uint32_t	set_color(char **d)
{
	int			i;
	int			j;
	int			num;
	uint32_t	color;

	i = 0;
	color = 0;
	while (d[i])
	{
		j = 0;
		while (d[i][j])
			num = num * 10 + (d[i][j++] - '0');
		color |= num; //adding bits from num into color 
		color <<= 8; //shifting 8 to the left
		i++;
	}
	color |= 255; //setting alpha = brightness
	return (color);
}
// 255, 254, 253
// 255 = 11111111
// 254 = 11111110
// 253 = 11111101
// 00000000, 00000000, 00000000, 00000000 = 00000000, 00000000, 00000000, 11111111
// 00000000, 00000000, 00000000, 11111111 <<= 8
// = 00000000, 00000000, 11111111, 00000000 
// 00000000, 00000000, 11111111, 00000000 |= 00000000, 00000000, 00000000, 11111110
// = 00000000, 00000000, 11111111, 11111110 <<= 8
// = 00000000, 11111111, 11111110, 00000000
// 00000000, 11111111, 11111110, 00000000 |= 00000000, 00000000, 00000000, 11111101
// = 00000000, 11111111, 11111110, 11111101 <<= 8
// = 11111111, 11111110, 11111101, 00000000

int	process_color(t_configs *data, char *path, char which)
{
	int		i;
	char	**d;

	i = 0;
	d = gc_split(path, ',', TEXT);
	if (!d)
		return (-1);
	while (d[i])
	{
		if (d[i][0] == '\0')
			return (printf("1Error: Invalid color code!\n"), -1);
		if (str_isdigit(d[i]) < 0)
			return (printf("2Error: Invalid color code!\n"), -1);
		i++;
	}
	if (i != 3)
		return (printf("3Error: Invalid color code!\n"), -1);
	if (which == 'F')
		data->textures->f_clr = set_color(d);
	else
		data->textures->c_clr = set_color(d);
	return (0);
}

int	check_textures(t_configs *data, int i, char *path, int error)
{
	data->textures = (t_textures *)gc_malloc(sizeof(t_textures), TEXT);
	if (!data->textures)
		return (-1);
	while (++i < 6)
	{
		path = get_path(data->txtrs[i]);
		if (data->txtrs[i][0] == 'F' || data->txtrs[i][0] == 'C')
			error = process_color(data, path, data->txtrs[i][0]);
		else
		{
			if (data->txtrs[i][0] == 'N')
				error = process_texture(data, path, data->txtrs[i][0] < 0);
			if (data->txtrs[i][0] == 'S')
				error = process_texture(data, path, data->txtrs[i][0] < 0);
			if (data->txtrs[i][0] == 'W')
				error = process_texture(data, path, data->txtrs[i][0] < 0);
			if (data->txtrs[i][0] == 'E')
				error = process_texture(data, path, data->txtrs[i][0] < 0);
		}
		if (error < 0)
			return (-1);
	}
	return (0);
}
