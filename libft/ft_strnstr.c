/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:36:03 by bolcay            #+#    #+#             */
/*   Updated: 2024/11/10 18:55:12 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr( const char *haystack, const char *needle, size_t c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < c)
	{
		while (haystack[i + j] == needle[j] && (i + j) < c && haystack[i + j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		j = 0;
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	const char *haystack = "this is a test broski";
	const char *needle = "";
	size_t c = 9;
	printf("%s", ft_strnstr(haystack, needle, c));
	return (0);
}
*/