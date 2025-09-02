/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:16:58 by cbauer            #+#    #+#             */
/*   Updated: 2025/08/07 16:04:52 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gc.h"

static int	ft_readstr(char const *s, char c)
{
	int	strcount;
	int	i;

	i = 0;
	strcount = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		while (s[i] == c && s[i] != '\0')
			i++;
		strcount++;
	}
	return (strcount);
}

static char	**ft_initarray(char const *s, char c, char **doublearray, int id)
{
	int		len;
	int		start;
	int		i;
	int		size;

	i = 0;
	start = 0;
	size = (ft_readstr(s, c) + 1) - 1;
	while (i < size)
	{
		while (s[start] == c && s[start] != '\0')
			start++;
		len = 0;
		while (s[start + len] != c && s[start + len] != '\0')
			len++;
		doublearray[i] = gc_substr(s, start, len, id);
		if (doublearray[i] == NULL)
			return (NULL);
		start = start + len;
		i++;
	}
	return (doublearray);
}

char	**gc_split(char const *s, char c, int id)
{
	int		size;
	char	**doublearray;

	size = (ft_readstr(s, c) + 1);
	if (!s)
		return (NULL);
	doublearray = gc_calloc (size, sizeof(char *), id);
	if (!doublearray)
		return (0);
	if (!ft_initarray(s, c, doublearray, id))
		return (NULL);
	return (doublearray);
}
