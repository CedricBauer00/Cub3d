/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:38:53 by cbauer            #+#    #+#             */
/*   Updated: 2024/10/26 16:54:04 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*string;
	size_t					counter;

	string = (const unsigned char *)s;
	counter = 0;
	while (counter < n)
	{
		if (string[counter] == (unsigned char)c)
		{
			return ((void *)(&string[counter]));
		}
		counter++;
	}
	return (NULL);
}
// int main()
// {
// 	char	str[] = "aasdasFFffdasd";
// 	printf("%s\n", ft_memchr(str, 'F', 10));
// 	return (0);
// }