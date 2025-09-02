/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:23:55 by cbauer            #+#    #+#             */
/*   Updated: 2025/08/07 14:26:00 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gc.h"

char	*gc_strdup(const char *str, int id)
{
	size_t	len;
	size_t	counter;
	char	*ptr;

	len = ft_strlen(str);
	ptr = gc_malloc(len * sizeof(char) + 1, id);
	if (!ptr)
		return (NULL);
	counter = 0;
	while (str[counter] != '\0')
	{
		ptr[counter] = str[counter];
		counter++;
	}
	ptr[counter] = '\0';
	return (ptr);
}
