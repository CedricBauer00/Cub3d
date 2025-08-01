/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:27:24 by cbauer            #+#    #+#             */
/*   Updated: 2024/10/26 16:03:32 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	if (needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[counter] != '\0' && counter < len)
	{
		i = 0;
		while (haystack[counter + i] == needle[i] && counter + i < len)
		{
			i++;
			if (needle[i] == '\0')
				return ((char *)&haystack[counter]);
		}
		counter++;
	}
	return (NULL);
}

// int main()
// {
// 	char haystack[17] = "fffffFoo Bar Baz";
// 	char needle[50] = "Foo Bar";
// 	printf("%s\n", ft_strnstr(haystack, needle, 15));
// 	printf("%s\n", strnstr(haystack, needle, 15));
// 	return (0);
// }