/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:54:06 by cbauer            #+#    #+#             */
/*   Updated: 2024/10/26 16:54:12 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					counter;
	const unsigned char		*string1;
	const unsigned char		*string2;

	string1 = (const unsigned char *)s1;
	string2 = (const unsigned char *)s2;
	counter = 0;
	while (counter < n)
	{
		if (string1[counter] != string2[counter])
			return (string1[counter] - string2[counter]);
		counter++;
	}
	return (0);
}

// int main()
// {
// 	char	str1[] = "asdasd";
// 	char	str2[] = "asdasd";
// 	printf("%d\n", ft_memcmp(str1, str2, 10));
// 	return (0);
// }