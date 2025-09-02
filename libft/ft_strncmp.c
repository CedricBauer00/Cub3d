/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:30:30 by cbauer            #+#    #+#             */
/*   Updated: 2024/10/18 14:55:44 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *src, const char *dest, size_t n)
{
	size_t	counter;

	counter = 0;
	if (n == 0)
		return (0);
	while ((counter < n) && !(src[counter] == '\0' && dest[counter] == '\0'))
	{
		if ((unsigned char)src[counter] != (unsigned char)dest[counter])
			return ((unsigned char)src[counter] - (unsigned char)dest[counter]);
		counter++;
	}
	return (0);
}

// int main()
// {
// 	char src[] = "";
// 	char dest[] = "";
// 	printf("%d\n", ft_strncmp(src, dest, 1));
// 	printf("%d\n", strncmp(src, dest, 3));
// 	return (0);
// }