/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:54:36 by cbauer            #+#    #+#             */
/*   Updated: 2024/12/09 12:59:05 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_errorcase(char **buf, char **line, int indic);
int		ft_checkfornewline(char *buf);
int		ft_readfile(int fd, char **buf, char **line);
int		ft_strlen(const char *tocount, int indic, int linebreakpos);
char	*managebuffer(char **buf, char **line, int *linebreakpos);
char	*get_next_line(int fd);
char	*ft_writeremainder(char **buffer, int *linebreakpos);
char	*ft_strjoin(char *s1, char *s2);

#endif
