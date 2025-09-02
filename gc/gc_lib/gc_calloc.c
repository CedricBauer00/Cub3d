/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:16:20 by cbauer            #+#    #+#             */
/*   Updated: 2025/08/07 14:22:45 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gc.h"

void	*gc_calloc(size_t count, size_t size, int id)
{
	int	*ptr;

	ptr = gc_malloc(count * size, id);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
