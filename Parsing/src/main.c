/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:32:55 by cbauer            #+#    #+#             */
/*   Updated: 2025/08/04 15:06:01 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_data(t_configs	*data)
{
	data->lines = NULL;
	data->lcount = 0;
	data->no_text = NULL;
	data->so_text = NULL;
	data->we_text = NULL;
	data->ea_text = NULL;
	data->f_clr = -1; //initialized to 'no color'
	data->c_clr = -1; //initialized to 'no color'
	data->m_hight = 0;
	data->m_width = 0;
	data->map = NULL;
	data->x_pos = -1; //-1 = out_of_map_pos
	data->y_pos = -1; //-1 = out_of_map_pos
	data->plr_dir = '\0'; //'no_direction'
}

int	read_from_file(char **argv, t_configs *data)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("\033[31mError: Could not read from file! Try another one.\n\
			\033[0m");
		return (-1);
	}
	if (get_next_line(fd) == NULL)
			return (printf("\033[31mEmpty file!\n\033[0m"), -1);
	data->lcount++;
	
	// while (get_next_line(fd))
	// {
	// 	lines = 
	// 	data->lcount++;
	// }
	close (fd);
	return (0);
}

int	correct_name(char **argv)
{
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(argv[1]);
	if (i <= 4)
		return (printf("Error: Map name too short!\n"), -1);
	i -= 4;
	if (ft_strncmp(argv[1] + i, ".cub", 4) != 0)
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
	if (correct_name(argv) < 0)
		return (-1);
	if (read_from_file(&argv[1], &data) < 0)
		return (-1);
}