/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:28:17 by bolcay            #+#    #+#             */
/*   Updated: 2025/08/27 14:19:46 by bolcay           ###   ########.fr       */
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
	delete_textures(game);
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
	game->tex->sky = data->textures->c_clr;
	game->tex->floor = data->textures->f_clr;
	game_start(game, data);
	return (0);
}

void	init_texture(t_configs *d, t_game *g)
{
	g->tex->no = d->textures->no_text;
	g->tex->so = d->textures->so_text;
	g->tex->we = d->textures->we_text;
	g->tex->ea = d->textures->ea_text;
}
