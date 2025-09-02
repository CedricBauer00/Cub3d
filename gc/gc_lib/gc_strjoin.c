/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:23:55 by cbauer            #+#    #+#             */
/*   Updated: 2025/08/07 14:26:30 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gc.h"

char	*gc_strjoin(char const *s1, char const *s2, int id)
{
	char	*newstr;
	size_t	len;
	size_t	counter;
	size_t	i;

	if (s1[0] == '\0' && s2[0] == '\0')
		return (gc_strdup("", id));
	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *)gc_malloc((len + 1) * sizeof(char), id);
	if (!newstr)
		return (0);
	counter = -1;
	while (s1[++counter] != '\0')
		newstr[counter] = s1[counter];
	i = 0;
	while (s2[i] != '\0')
		newstr[counter++] = s2[i++];
	newstr[counter] = '\0';
	return (newstr);
}
