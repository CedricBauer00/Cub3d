/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:50:40 by bolcay            #+#    #+#             */
/*   Updated: 2024/11/08 17:10:30 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = 0;
	if (d_len >= dstsize)
		return (dstsize + s_len);
	while (i < (dstsize - d_len - 1) && src[i] != '\0')
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}

/*
#include <stdio.h>

int main()
{
    char dst[29] = "hey how are";
    const char *src = "1234567891123456";
    size_t dstsize = 9;
    printf("%zu", ft_strlcat(dst, src, dstsize));
    return (0);
}
*/