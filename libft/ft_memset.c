/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:25:35 by bolcay            #+#    #+#             */
/*   Updated: 2024/11/08 17:16:35 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	j;

	i = 0;
	j = c;
	tmp = b;
	while (i < len)
	{
		tmp[i] = j;
		i++;
	}
	return (b);
}
/*
#include <stdio.h>

int main()
{
    char b[] = "hows it goin";
    int c = 'b';
    size_t len = 2;
    printf("%s", ft_memset(b, c, len));
    return (0);
}
*/