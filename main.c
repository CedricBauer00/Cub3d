/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:28:17 by bolcay            #+#    #+#             */
/*   Updated: 2025/08/05 13:49:45 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int	i;
	int	j;
	t_game	*game;

	i = 0;
	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		return (0);
	game->mlx = mlx_init(1024, 512, "game", true);
	if (!game->mlx)
		return (0);
	initialize(game);
	paint_map(game, game->player->image);
	game->player->image = mlx_new_image(game->mlx, 1024, 512);
	while (i < 8)
	{
		j = 0;
		if (i == 3 || i == 4 || i == 5)
		{
			if (i == 4)
			{
				j = 0;
				while (j < 150)
				{
					mlx_put_pixel(game->player->image, 253 + i, 253 + j + 1, 0xFF0000FF);
					j++;
				}
			}
			j = 0;
			while (j < 20)
			{
				mlx_put_pixel(game->player->image, 253 + i, 253 + j + 1,0xFFFF00FF);
				j++;
			}
		}
		j = 0;
		while (j < 8)
		{
			mlx_put_pixel(game->player->image, 253 + i, 253 + j, 0x40E0D0);
			j++;
		}
		i++;
	}
	mlx_image_to_window(game->mlx, game->player->image, 0, 0);
	// mlx_delete_image(game->mlx, image);
	mlx_key_hook(game->mlx, key, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}
