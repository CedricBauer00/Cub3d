/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 09:46:20 by cbauer            #+#    #+#             */
/*   Updated: 2025/09/03 15:56:03 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <math.h>
# include "../src/gc/gc.h"
# include <../MLX42/include/MLX42/MLX42.h>
# include "../src/get_next_line/get_next_line.h"
# include "../src/libft/libft.h"

typedef struct s_textures
{
	//textures
	mlx_texture_t	*no_text;
	mlx_texture_t	*so_text;
	mlx_texture_t	*we_text;
	mlx_texture_t	*ea_text;

	//floor/ceeling
	uint32_t		f_clr;
	uint32_t		c_clr;
}	t_textures;

typedef struct s_map
{
	int				hight;
	int				width;
	char			**map;

	//player position 
	double			x_pos;
	double			y_pos;
	char			plr_dir;
}	t_map;

typedef struct s_configs
{
	char			**lines;
	int				lcount;
	char			**txtrs;
	t_textures		*textures;
	int				where_color_is;

	//map
	int				m_hight;
	int				m_width;
	char			**map;
	t_map			*map_info;
}	t_configs;

typedef struct s_seen
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
}	t_seen;

// ----------------------------------------------------------------------
//							  MAIN
// ----------------------------------------------------------------------

int			allocate_lines(char *argv1, t_configs *data);
int			init_lines(char *argv1, t_configs *data, int fd, char *tmp);
int			check_duplicate(char **lines);
int			seperate(t_configs *data);
int			main(int argc, char **argv);

// ----------------------------------------------------------------------
//							MAIN_UTILS
// ----------------------------------------------------------------------

bool		check_empty_line(char *line);
int			correct_name(char *argv1);
void		init_data(t_configs *data);
int			set_flags(t_seen *flags);
bool		ft_isspace(char c);

// ----------------------------------------------------------------------
//							FORMAT_TXTR
// ----------------------------------------------------------------------

char		*init_str(char *line, char *str, int len, int i);
int			init_txtrs(t_configs *data);
char		*cut_spaces(char *line);

// ----------------------------------------------------------------------
//							CHECK_TEXTURES
// ----------------------------------------------------------------------

// at this point data.txtrs array contains the correctly formatted input
// components line NO, EA, F, C, ... so now paths and colors can properly
// be checked - if they're valid they will be put into the data.textures array
// which contains the according MLX variables and color codes (if textures are
// valid they will be mlx_load_png() and put into the struct).

char		*get_path(char *str);
int			str_isdigit(char *str);
uint32_t	set_color(char **d);
int			process_color(t_configs *data, char *path, char which);
int			check_textures(t_configs *data, int i, char *path, int error);

// ----------------------------------------------------------------------
//							INIT_MAP
// ----------------------------------------------------------------------

int			process_texture(t_configs *data, char *path, char which);

// ----------------------------------------------------------------------
//							INIT_MAP
// ----------------------------------------------------------------------

// so far we have parsed the input configurations into the data.textures struct
// which will contain only correct components - will be parsed to execution
// now we will put the map in a seperate array 'data.map' and do the checking on
// this variable cs its easier to have seperate map variable.

void		per_line(t_configs *data, char *line, int i, int len);
int			allocate_map(t_configs *data, int i);
int			init_map_helper(t_configs *data, int i, int j);
void		init_map(t_configs *data, int i, int j, int l);
int			create_map(t_configs *data);

// ----------------------------------------------------------------------
//							INIT_MAP
// ----------------------------------------------------------------------

int			check_map(t_configs *data, char **map);

// ----------------------------------------------------------------------
//								PLAYER
// ----------------------------------------------------------------------

// here we check if the player components in the map are valid or not -
//additionally I allocate 't_map data.map_info' struct, which will contrain
// all crucial information about the player and the map; X, Y position of player
// starting direction; map array, map hight, map width - so you can work only
// with this and the data.textures struct
// those 2 struct contain all the information that is important for you.

int			get_player(t_configs *data, int i, int j, char c);
int			player(t_configs *data);

// ----------------------------------------------------------------------
//								FLOOD_FILL
// ----------------------------------------------------------------------

int			flood_fill(t_configs *data, int y, int x, char **map);
int			set_up_fl(t_configs *data);

// ----------------------------------------------------------------------
//								 BONUS
// ----------------------------------------------------------------------

int			check_doors(t_configs *data, char **map, int i, int j);

// the GC uses 4 seperate lists: 
//	PARS: with this list we allocate only variables that we use as tools for 
//the parsing 
// - WILL BE FREED AFTER THE PARSING PART
//	MAP: in this list we I store the struct of the map struct that is neccessary
// creating the map in execution
// - FREE AFTER EXECUTION
//	TEXT: we store mlx varibles that we need to delete after game end
// - WILL BE FREED AFTER EXECUTION
//	EXEC: we store utility variables that we need for the execution
// - WILL BE FREED AFTER EXECUTION

#endif