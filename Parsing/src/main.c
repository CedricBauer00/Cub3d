/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:32:55 by cbauer            #+#    #+#             */
/*   Updated: 2025/08/01 12:04:11 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_data(t_setup	*data)
{
	data->lines = NULL;
	data->lcount = 0;
}

int	main(int argc, char **argv)
{
	t_setup data;

	if (argc != 2)
		return (printf("Error: Too many/few arguments!"), -1);
	init_struct(&data);
	
}