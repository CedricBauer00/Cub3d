/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:18:04 by cbauer            #+#    #+#             */
/*   Updated: 2025/08/19 13:53:01 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

t_which	*get_id(int id)
{
	t_which	*which;

	which = get_gc()->head;
	while (which)
	{
		if (which->id == id)
			return (which);
		which = which->next;
	}
	which = (t_which *)malloc(sizeof(t_which));
	if (!which)
		return (printf("Error: GC failed!\n"), NULL);
	which->id = id;
	which->list = NULL;
	which->next = get_gc()->head;
	get_gc()->head = which;
	return (which);
}

void	*gc_malloc(size_t size, int id)
{
	t_which	*which;
	t_gc	*new_node;
	void	*ptr;

	which = get_id(id);
	if (!which)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
		return (printf("Error: GC failed!\n"), NULL);
	new_node = (t_gc *)malloc(sizeof(t_gc));
	if (!new_node)
		return (printf("Error: GC failed!\n"), free(ptr), NULL);
	new_node->mem = ptr;
	new_node->next = which->list;
	which->list = new_node;
	return (ptr);
}

t_head	*get_gc(void)
{
	static t_head	gc = {0};

	return (&gc);
}

void	gc_free_all(void)
{
	t_which	*which;
	t_which	*temp;

	which = get_gc()->head;
	while (which)
	{
		temp = which;
		which = which->next;
		gc_free_helper(temp->list);
		free(temp);
	}
	get_gc()->head = NULL;
}

void	gc_free(int id)
{
	t_which	*which;
	t_which	*temp;

	temp = NULL;
	which = get_gc()->head;
	while (which)
	{
		if (which->id == id)
		{
			if (temp)
				temp->next = which->next;
			else
				get_gc()->head = which->next;
			gc_free_helper(which->list);
			return ;
		}
		temp = which;
		which = which->next;
	}
}
