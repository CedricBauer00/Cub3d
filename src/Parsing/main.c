/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:32:55 by cbauer            #+#    #+#             */
/*   Updated: 2025/09/02 22:38:10 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	allocate_lines(char *argv1, t_configs *data)
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
	if (data->lcount < 9)
		return (printf("Error: Too little lines!\n"), -1);
	data->lines = (char **)gc_malloc(sizeof(char *) * (data->lcount + 1), PARS);
	if (!data->lines)
		return (close(fd), -1);
	data->lines[data->lcount] = NULL;
	close(fd);
	return (0);
}

int	init_lines(char *argv1, t_configs *data, int fd, char *tmp)
{
	fd = open(argv1, O_RDONLY);
	if (fd < 0)
	{
		return (printf("\033[31mError: Could not read from file!"),
			printf("Try another one.\n\033[0m"), -1);
	}
	allocate_lines(argv1, data);
	tmp = get_next_line(fd);
	data->lcount = 0;
	while (tmp != NULL)
	{
		if (check_empty_line(tmp) == true) // if true, increment count
			data->lines[data->lcount++] = gc_substr(tmp, 0,
				ft_strlen(tmp), PARS);
		if (!data->lines[data->lcount - 1])
			return (free(tmp), -1);
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

int	check_duplicate(char **lines)
{
	int		i;
	t_seen	flags;

	i = -1;
	if (set_flags(&flags) < 0)
		return (-1);
	while (++i < 6)
	{
		if (ft_strncmp(lines[i], "NO ", 3) == 0)
			flags.no++;
		if (ft_strncmp(lines[i], "SO ", 3) == 0)
			flags.so++;
		if (ft_strncmp(lines[i], "WE ", 3) == 0)
			flags.we++;
		if (ft_strncmp(lines[i], "EA ", 3) == 0)
			flags.ea++;
		if (ft_strncmp(lines[i], "F ", 2) == 0)
			flags.f++;
		if (ft_strncmp(lines[i], "C ", 2) == 0)
			flags.c++;
	}
	if (flags.no != 1 || flags.so != 1 || flags.we != 1 || flags.ea != 1
		|| flags.f != 1 || flags.c != 1)
		return (printf("Error: Input error: Duplicates/Missing lines!\n"), -1);
	return (0);
}

int	seperate(t_configs *data)
{
	data->txtrs = (char **)gc_malloc(sizeof(char *) * 7, PARS);
	if (!data->txtrs)
		return (-1);
	if (init_txtrs(data) < 0)
		return (-1);
	if (check_duplicate(data->txtrs) < 0)
		return (-1);
	if (check_textures(data, -1, NULL, 0) < 0)
		return (-1);
	if (create_map(data) < 0)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_configs	data;

	if (argc != 2)
		return (printf("Error: Too many/few arguments!\n"), -1);
	init_data(&data);
	if (correct_name(argv[1]) < 0)
		return (gc_free_all(), -1);
	if (init_lines(argv[1], &data, 0, NULL) < 0)
		return (gc_free_all(), -1);
	gc_free(PARS);
	//EXECUTION!
	if (execute_main(&data) < 0)
		return (printf("Error: Execution failed!\n"), gc_free_all(), -1);
	gc_free_all(); //	DELETE MLX TEXTURES with mlx_delete_texture(test) - DID NOT HAPPEN YET
	return (0);
}
