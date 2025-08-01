/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:18:02 by bolcay            #+#    #+#             */
/*   Updated: 2024/11/08 17:12:40 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	j;
	char	*new_s;

	i = 0;
	j = ft_strlen(s);
	new_s = (char *) malloc(j + 1);
	if (new_s == 0)
		return (0);
	while (s[i])
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

/*
#include <stdio.h>

int main()
{
    const char *s = "broski why";
    printf("%s", ft_strdup(s));
    free(ft_strdup(s));
    return (0);
}
*/