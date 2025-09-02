/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:23:55 by cbauer            #+#    #+#             */
/*   Updated: 2025/08/07 14:25:37 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gc.h"

char	*gc_substr(char const *s, unsigned int start, size_t len, int id)
{
	char	*substr;
	size_t	counter;
	size_t	i;

	if (len == 0)
		return (gc_strdup("", id));
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (gc_strdup("", id));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = (char *)gc_malloc((len + 1) * sizeof(char), id);
	if (!substr)
		return (NULL);
	counter = start;
	i = 0;
	while (counter < len + start)
	{
		substr[i] = s[counter];
		counter++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
