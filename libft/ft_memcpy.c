/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:37:30 by bolcay            #+#    #+#             */
/*   Updated: 2024/11/10 19:06:22 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*c_dst;
	const unsigned char	*c_src;
	size_t				i;

	if (dst == NULL && src == NULL)
		return (dst);
	i = 0;
	c_dst = (unsigned char *) dst;
	c_src = (const unsigned char *) src;
	while (i < n)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char dst[20];
    const char src[15] = "123456789123456";
    size_t n = sizeof(src) - 1;

    ft_memcpy(dst, src, n);
    dst[n] = '\0';
    printf("%s", ft_memcpy(dst, src, n));
    return (0);
}
*/