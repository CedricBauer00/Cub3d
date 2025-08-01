/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:23:06 by cbauer            #+#    #+#             */
/*   Updated: 2024/12/10 17:47:30 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_checkfornewline(char *line)
{
	int	c;

	c = 0;
	if (line == NULL)
		return (0);
	while (line[c] != '\0')
	{
		if (line[c] == '\n')
			return (1);
		c++;
	}
	return (0);
}

void	ft_errorcase(char **buf, char **line, int indic)
{
	if (*buf)
	{
		free(*buf);
		*buf = NULL;
	}
	if (*line && indic == 0)
	{
		free(*line);
		*line = NULL;
	}
	if (*line && line[0][0] == '\0' && (indic == 1))
	{
		free(*line);
		*line = NULL;
	}
	return ;
}

int	ft_readfile(int fd, char **buf, char **line)
{
	int	i;

	i = 0;
	i = read(fd, *buf, BUFFER_SIZE);
	if (i == 0 && buf[0])
	{
		ft_errorcase(buf, line, 1);
		return (0);
	}
	if (i < 0)
	{
		ft_errorcase(buf, line, 0);
		return (-1);
	}
	buf[0][i] = '\0';
	return (i);
}

char	*managebuffer(char **buf, char **line, int *linebreakpos)
{
	if (buf[0] != NULL)
	{
		line[0] = ft_writeremainder(buf, linebreakpos);
		if (!line[0])
			return (NULL);
	}
	if (!*buf)
	{
		buf[0] = malloc(BUFFER_SIZE + 1);
		if (!buf[0])
			return (NULL);
		buf[0][0] = '\0';
	}
	if (line[0] == NULL)
	{
		line[0] = (char *)malloc(1 * sizeof(char));
		if (!line[0])
		{
			if (*buf)
				free(buf);
			return (NULL);
		}
		line[0][0] = '\0';
	}
	return (line[0]);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	static int	linebreakpos;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	line = managebuffer(&buf, &line, &linebreakpos);
	if (!line)
		return (NULL);
	while (buf[0] == '\0' || ft_checkfornewline(line) == 0)
	{
		linebreakpos = 0;
		i = ft_readfile(fd, &buf, &line);
		if (i > 0)
			line = ft_strjoin(line, buf);
		if (i < 0)
			return (NULL);
		if (i == 0)
			break ;
	}
	while (buf && buf[linebreakpos] != '\n' && buf[linebreakpos] != '\0')
		linebreakpos++;
	return (line);
}

// int main(void)
// {
// 	int fd;
// 	int	i;
// 	char *line;

// 	i = 0;
// 	fd = open("text.txt", O_RDONLY);
// 	while (i < 6)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// 	// line = get_next_line(fd);
// 	// printf("%s", line);
// 	// free (line);
// 	close (fd);
// 	return(0);
// }

// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <stddef.h>
// #include <fcntl.h>
// #include "get_next_line.h"

// #include <fcntl.h>
// #include <stdio.h>

// int main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("text.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	// line = get_next_line(fd);
// 	// printf("%s", line);
// 	// free (line);
// 	close (fd);
// 	return(0);
// }

// int main(void)
// {
// 	// int fd;
// 	char *line;
// 	// fd = open("text.txt", O_RDONLY);
// 	while ((line = get_next_line(0)) != NULL && line[0] != 'a')
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	// close(fd);
// 	return (0);
// }