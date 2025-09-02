/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:00:44 by cbauer            #+#    #+#             */
/*   Updated: 2024/10/26 16:16:29 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*newliststart;
	void	*newcontent;

	newliststart = NULL;
	while (lst != NULL)
	{
		newcontent = f(lst->content);
		if (!newcontent)
		{
			ft_lstclear(&newliststart, del);
			return (NULL);
		}
		newnode = ft_lstnew(newcontent);
		if (!newnode)
		{
			del(newcontent);
			ft_lstclear(&newliststart, del);
			return (NULL);
		}
		ft_lstadd_back(&newliststart, newnode);
		lst = lst->next;
	}
	return (newliststart);
}
