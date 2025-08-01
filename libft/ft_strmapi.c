/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:05:26 by bolcay            #+#    #+#             */
/*   Updated: 2024/11/08 18:30:32 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	unsigned int		j;
	char				*new_s;

	i = 0;
	j = ft_strlen(s);
	new_s = (char *)malloc (j + 1);
	if (!new_s)
		return (NULL);
	while (i < j)
	{
		new_s[i] = f(i, s[i]);
		i ++;
	}
	new_s[i] = '\0';
	return (new_s);
}
