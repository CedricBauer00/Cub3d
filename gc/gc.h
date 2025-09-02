/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 09:24:02 by cbauer            #+#    #+#             */
/*   Updated: 2025/08/19 09:51:14 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef enum e_id
{
	PARS,
	MAP,
	TEXT,
	EXEC,
}	t_id;

typedef struct s_gc
{
	void			*mem;
	struct s_gc		*next;
}	t_gc;

typedef struct s_which
{
	int				id;
	t_gc			*list;
	struct s_which	*next;
}	t_which;

typedef struct s_head
{
	t_which			*head;
}	t_head;

// ----------------------------------------------------------------------
//								GC_MAIN
// ----------------------------------------------------------------------

t_which	*get_id(int id);
void	*gc_malloc(size_t size, int id);
t_head	*get_gc(void);
void	gc_free_all(void);
void	gc_free(int id);

// ----------------------------------------------------------------------
//								GC_HELPER
// ----------------------------------------------------------------------

void	gc_free_helper(t_gc *list);

// ----------------------------------------------------------------------
//								GC_LIB
// ----------------------------------------------------------------------

void	*gc_calloc(size_t count, size_t size, int id);
char	*gc_itoa(int n, int id);
char	**gc_split(char const *s, char c, int id);
char	*gc_strdup(const char *str, int id);
char	*gc_strjoin(char const *s1, char const *s2, int id);
char	*gc_substr(char const *s, unsigned int start, size_t len, int id);

#endif