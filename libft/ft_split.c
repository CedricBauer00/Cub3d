/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:08:24 by bolcay            #+#    #+#             */
/*   Updated: 2024/11/11 19:45:56 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_word(const char *str, int start, int end);
static	int	ft_count(const char *str, int j);
static void	*ft_clean(char **str, int j);

char	**ft_split(char const *s, char c)
{
	int		start;
	int		end;
	int		i;
	char	**temp;

	i = 0;
	end = 0;
	temp = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!temp)
		return (NULL);
	while (s[end] == c && s[end])
		end++;
	while (s[end])
	{
		start = end;
		while (s[end] != c && s[end])
			end++;
		temp[i++] = ft_word(s, start, end);
		if (!temp[i - 1])
			return (ft_clean(temp, i - 1));
		while (s[end] == c && s[end])
			end++;
	}
	temp[i] = NULL;
	return (temp);
}

static	int	ft_count(const char *str, int j)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == j)
			i++;
		if (str[i] && str[i] != j)
		{
			count++;
			while (str[i] && str[i] != j)
				i++;
		}
	}
	return (count);
}

static char	*ft_word(const char *str, int start, int end)
{
	int		i;
	char	*new;

	i = 0;
	new = (char *)malloc((end - start + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (start < end)
	{
		new[i] = str[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}

static void	*ft_clean(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (0);
}
/*
int	main(void)
{
	char const *s = "  we will rock you";
	char c = ' ';
	printf("%s", *ft_split(s, c));
	return (0);
}
*/