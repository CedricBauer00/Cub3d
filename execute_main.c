/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:28:17 by bolcay            #+#    #+#             */
/*   Updated: 2025/08/27 11:12:59 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// mlx_loop_hook keeps updating the frame over and over

int	game_start(t_game *game, t_configs *data)
{
	init_texture(data, game);
	initialize(data->map_info, game);
	game->player->image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->player->minimap = mlx_new_image(game->mlx, WIDTH / 3, HEIGHT / 3);
	draw_player(game);
	draw_minimap(game, game->player->minimap, 0, -1);
	mlx_image_to_window(game->mlx, game->player->image, 0, 0);
	mlx_image_to_window(game->mlx, game->player->minimap, 10, 10);
	mlx_key_hook(game->mlx, key, game);
	mlx_cursor_hook(game->mlx, cursor, game);
	mlx_loop_hook(game->mlx, update_frame, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}

int	execute_main(t_configs *data)
{
	t_game	*game;

	game = gc_malloc(sizeof(t_game), EXEC);
	if (!game)
		return (-1);
	game->player = gc_malloc(sizeof(t_player), EXEC);
	if (!game->player)
		return (-1);
	game->tex = gc_malloc(sizeof(t_tex), EXEC);
	if (!game->tex)
		return (-1);
	game->ray = gc_malloc(sizeof(t_ray), EXEC);
	if (!game->ray)
		return (-1);
	game->mlx = mlx_init(WIDTH, HEIGHT, "game", true);
	if (!game->mlx)
		return (-1);
	game_start(game, data);
	return (0);
}

// static void	ft_uppercase_hex(unsigned int nbr, int i, int check)
// {
// 	unsigned int	copy;
// 	char			number[9];

// 	copy = nbr;
// 	while (copy > 0)
// 	{
// 		if (copy % 16 >= 10)
// 			number[i++] = copy % 16 + 'A' - 10;
// 		else
// 			number[i++] = copy % 16 + 48;
// 		copy /= 16;
// 	}
// 	number[i] = '\0';
// 	while (i > 0)
// 	{
// 		check = write(1, &number[--i], 1);
// 	}
// }

void	init_texture(t_configs *d, t_game *g)
{
	// (void)d;
	g->tex->no = d->textures->no_text;
	g->tex->so = d->textures->so_text;
	g->tex->we = d->textures->we_text;
	g->tex->ea = d->textures->ea_text;
	g->tex->no_tex = mlx_texture_to_image(g->mlx, d->textures->no_text);
	g->tex->so_tex = mlx_texture_to_image(g->mlx, d->textures->so_text);
	g->tex->we_tex = mlx_texture_to_image(g->mlx, d->textures->we_text);
	g->tex->ea_tex = mlx_texture_to_image(g->mlx, d->textures->ea_text);
}
