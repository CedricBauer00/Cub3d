/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:33:11 by bolcay            #+#    #+#             */
/*   Updated: 2024/11/08 19:53:42 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t c)
{
	size_t	i;

	i = 0;
	while (i < c && s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < c)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
/*
int	main(void)
{
	const char	*s1 = "test";
	const char	*s2 = "tests";
	size_t	c = 15;

	printf("%d", ft_strncmp(s1, s2, c));
	return (0);
}
*/