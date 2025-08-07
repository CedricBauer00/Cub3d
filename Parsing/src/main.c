/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:32:55 by cbauer            #+#    #+#             */
/*   Updated: 2025/08/07 14:49:11 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_data(t_configs	*data)
{
	data->lines = NULL;
	data->lcount = 0;
	data->m_hight = 0;
	data->m_width = 0;
	data->map = NULL;
	data->x_pos = -1; //-1 = out_of_map_pos
	data->y_pos = -1; //-1 = out_of_map_pos
	data->plr_dir = '\0'; //'no_direction'
}

bool	check_empty_line(char *line) //checks if a line in the map.cub file is empty - so it can be skipped by returning false
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\n')
		return (false);
	return (true);
}

int	get_lines(char *argv1, t_configs *data)
{
	int		fd;
	char	*str;

	fd = open(argv1, O_RDONLY);
	if (fd < 0)
	{
		return (printf("\033[31m!Error: Could not read from file!"),
		printf("Try another one.\n\033[0m"), -1);
	}
	str = get_next_line(fd);
	while (str != NULL)
	{
		if (check_empty_line(str) == true) // if true, increment count
			data->lcount++;
		free(str);
		str = get_next_line(fd);
	}
	data->lines = (char **)gc_malloc(sizeof(char *) * (data->lcount + 1), PARS); 
	if (!data->lines)
		return (close(fd), -1);
	data->lines[data->lcount] = NULL;
	close(fd);
	return (0);
}

int	read_from_file(char *argv1, t_configs *data, int fd, char *tmp)
{
	fd = open(argv1, O_RDONLY);
	if (fd < 0)
	{
		return (printf("\033[31mError: Could not read from file!"),
		printf("Try another one.\n\033[0m"), -1);
	}
	get_lines(argv1, data);
	tmp = get_next_line(fd);
	data->lcount = 0;
	while (tmp != NULL)
	{
		if (check_empty_line(tmp) == true) // if true, increment count
			data->lines[data->lcount++] = gc_substr(tmp, 0,
				ft_strlen(tmp), PARS); 
		free(tmp);
		tmp = get_next_line(fd);
	}
	if (data->lines[0] == NULL)
		return (close (fd), printf("\033[31mEmpty file!\n\033[0m"), -1);
	close (fd);
	if (seperate(data) < 0)
		return (-1);
	return (0);
}

int	correct_name(char *argv1)
{
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(argv1);
	if (i <= 4)
		return (printf("Error: Map name too short!\n"), -1);
	i -= 4;
	if (ft_strncmp(argv1 + i, ".cub", 4) != 0)
	{
		printf("Error: Incorrect naming! Try a file ending with .cub\n");
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_configs data;

	if (argc != 2)
		return (printf("Error: Too many/few arguments!\n"), -1);
	init_data(&data);
	if (correct_name(argv[1]) < 0)
		return (-1);
	if (read_from_file(argv[1], &data, 0, NULL) < 0)
	return (gc_free_all(), -1);
	// for (int i = 0; data.lines[i] != NULL; i++)
	// 	printf("%s", data.lines[i]);
	gc_free(PARS);
	//EXECUTION!
	
	gc_free_all();
	return (0);
}
