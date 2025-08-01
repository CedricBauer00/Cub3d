/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:47:57 by bolcay            #+#    #+#             */
/*   Updated: 2024/11/11 15:38:34 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*t_dst;
	char	*t_src;

	if (!dst && !src)
		return (NULL);
	t_dst = (char *) dst;
	t_src = (char *) src;
	if (t_dst < t_src)
	{
		i = 0;
		while (i < len)
		{
			t_dst[i] = t_src[i];
			i++;
		}
	}
	if (t_dst > t_src)
	{
		while (len-- > 0)
			t_dst[len] = t_src[len];
	}
	return (dst);
}
