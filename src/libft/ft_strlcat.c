/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:08:03 by cbauer            #+#    #+#             */
/*   Updated: 2024/10/26 16:56:09 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	counter = 0;
	i = 0;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (dst[counter] != '\0')
		counter++;
	while (i < dstsize - dst_len -1 && src[i] != '\0')
	{
		dst[counter + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// int main()
// {
// 	char dest[15] = 'a';
// 	char dest2[15] = 'a';
//     printf("%zu\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
//     printf("%zu\n", strlcat(dest2, "lorem ipsum dolor sit amet", 15));
//     write(1, "\n", 1);
//     write(1, dest, 15);
//     write(1, "\n", 1);
//     write(1, dest2, 15);
// // 	char src[] = "the cake is a lie !\0I'm hidden lol\r\n";
// // 	char dest[60] = "there is no stars in the sky";
// // 	char dest2[60] = "there is no stars in the sky";
// // 	size_t max = 60;
// // 	printf("%s\n", dest);
// // 	printf("%zu\n", ft_strlcat(dest, src, max));
// // 	printf("%s\n", dest);
// // 	printf("%zu\n", strlcat(dest2, src, max));
// 	return (0);
// }
