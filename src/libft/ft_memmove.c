/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:44:14 by cbauer            #+#    #+#             */
/*   Updated: 2024/10/26 16:54:37 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				counter;
	unsigned char		*destination;
	const unsigned char	*source;

	destination = (unsigned char *)dst;
	source = (const unsigned char *)src;
	if (len == 0)
		return (dst);
	if (destination > source)
	{
		counter = len;
		while (counter > 0)
		{
			destination[counter - 1] = source[counter - 1];
			counter--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

// int main()
// {
// 	char dst[] = "DSDSDSDSD";
// 	const char src[] = "AAAAAAAA";
// 	printf("%s\n", ft_memmove(dst, src, 4));
// 	return (0);
// }