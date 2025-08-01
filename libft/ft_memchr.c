/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:26:20 by bolcay            #+#    #+#             */
/*   Updated: 2024/11/10 18:17:59 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*j;
	unsigned char	k;

	i = 0;
	j = (unsigned char *) s;
	k = (unsigned char) c;
	while (i < n)
	{
		if (j[i] == k)
			return ((unsigned char *) &j[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int main()
{
    const char s[] = "howdy";
    int c = 'o';
    size_t n = 5;
    printf("%s", ft_memchr(s, c, n));
    return (0);
}
*/