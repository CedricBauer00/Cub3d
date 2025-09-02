/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:57:23 by cbauer            #+#    #+#             */
/*   Updated: 2025/09/02 22:29:39 by batuhan          ###   ########.fr       */
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
