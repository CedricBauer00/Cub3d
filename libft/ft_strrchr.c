/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:18:20 by bolcay            #+#    #+#             */
/*   Updated: 2024/11/10 16:47:16 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (s[i])
	{
		if (s[i] == (char) c)
			j = i;
		i++;
	}
	if (j != -1)
		return ((char *) &s[j]);
	else if (s[i] == (char) c)
		return ((char *) &s[i]);
	return (0);
}
/*
#include <stdio.h>

int main()
{
    const char *s = "yoo how you doin";
    int c = 'o';
    printf("%s", ft_strrchr(s, c));
    return (0);
}
*/