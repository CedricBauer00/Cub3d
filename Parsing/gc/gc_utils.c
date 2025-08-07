/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:57:23 by cbauer            #+#    #+#             */
/*   Updated: 2025/08/07 14:16:16 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	gc_free_helper(t_gc *list)
{
	t_gc	*gc_temp;

	while (list)
	{
		gc_temp = list;
		list = list->next;
		free(gc_temp->mem);
		free(gc_temp);
	}
}

