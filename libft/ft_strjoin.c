/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:53:55 by bolcay            #+#    #+#             */
/*   Updated: 2024/11/08 17:12:00 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new_s;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	new_s = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_s)
		return (NULL);
	while (s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new_s[i + j] = s2[j];
		j++;
	}
	new_s[i + j] = '\0';
	return (new_s);
}
/*

int main()
{
    char const *s1 = "my name is ";
    char const *s2 = "Batuhan";
    printf("%s", ft_strjoin(s1, s2));
    return (0);
}
*/