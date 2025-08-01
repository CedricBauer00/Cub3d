/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:43:53 by bolcay            #+#    #+#             */
/*   Updated: 2024/11/08 20:40:22 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*j;
	unsigned char	*k;
	size_t			i;

	i = 0;
	j = (unsigned char *) s1;
	k = (unsigned char *) s2;
	while (i < n)
	{
		if (j[i] == k[i])
			i++;
		else
			return (j[i] - k[i]);
	}
	return (0);
}
/*
#include <stdio.h>

int main()
{
    const char *s1 = "hodwy partner";
    const char *s2 = "howdy partnre";
    size_t n = 15;
    printf("%d", ft_memcmp(s1, s2, n));
    return (0);
}
*/