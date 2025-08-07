/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_txtr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:29:54 by cbauer            #+#    #+#             */
/*   Updated: 2025/08/07 14:49:48 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	*init_str(char *line, char *str, int len, int i)
{
	int	j;

	j = 0;
	str = (char *)gc_malloc(sizeof(char) * len + 1, PARS);
	if (!str)
		return (NULL);
	while (i < len)
	{
		if (!ft_isspace(line[i]))
			str[j++] = line[i++];
		else
		{
			while (ft_isspace(line[i]))
				i++;
			str[j++] = ' ';
		}
	}
	str[len] = '\0';
	return (str);
}

char	*cut_spaces(char *line)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while (ft_isspace(line[i]))
		i++;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			i++;
		else
		{
			while (ft_isspace(line[i]))
				i++;
		}
		if (line[i] != '\0')
			len++;
	}
	str = init_str(line, NULL, len, 0);
	if (!str)
		return (NULL);
	return (str);
}

int	init_txtrs(t_configs *data)//char **txtrs kann ich das machen?
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		data->lines[i] = cut_spaces(data->lines[i]);
		if (!data->lines[i])
			return (-1);
	}
	i = -1;
	while (++i < 6)
		data->txtrs[i] = data->lines[i];
	data->txtrs[6] = NULL;
	return (0);
}
