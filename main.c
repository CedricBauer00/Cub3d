/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:28:17 by bolcay            #+#    #+#             */
/*   Updated: 2025/08/07 08:38:32 by bolcay           ###   ########.fr       */
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
	game->mlx = mlx_init(512, 512, "game", true);
	if (!game->mlx)
		return (0);
	initialize(game);
	paint_map(game, game->player->image);
	game->player->image = mlx_new_image(game->mlx, 512, 512);
	draw_player_ex(game, game->player->image);
	mlx_image_to_window(game->mlx, game->player->image, 127, 126);

	mlx_key_hook(game->mlx, key, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}
