/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 09:46:20 by cbauer            #+#    #+#             */
/*   Updated: 2025/08/27 12:45:09 by cbauer           ###   ########.fr       */
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
# include "../gc/gc.h"
# include <MLX42/MLX42.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

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

int		allocate_lines(char *argv1, t_configs *data); // counts how many lines the data.lines array needs to have and allocates it - immediatly checks of the minimum of input lines is given, if not error.
int		init_lines(char *argv1, t_configs *data, int fd, char *tmp); // calls allocate_lines() - initialyzes data.lines by substr(of GNL string - allocs in PARS GC list ) - calls check_empty_line() while inititalizing - calls seperate() at the end.
int		check_duplicate(char **lines); // calls set_flags() - checks crucial input components (NO, EA, F, C, ...) and sets flags accordingly.
int		seperate(t_configs *data); // allocates data.txtrs (array in which textures components are stored to check on validity) calls init_txtrs() - after check_duplicate() - after check_textures() - after create_map().
int		main(int argc, char **argv); // calls init_data() - afterwards correct_name() - after init_lines.

// ----------------------------------------------------------------------
//							MAIN_UTILS
// ----------------------------------------------------------------------

bool	check_empty_line(char *line); // checks if a line in the map.cub file is empty - so it can be skipped by returning false.
int		correct_name(char *argv1); // checks on the correct input name - *.cub otherwise error.
void	init_data(t_configs *data); // sets the data. variables default (NULL/0).
int		set_flags(t_seen *flags); // sets flags to 0 - to check if crucial input component is found or not.
bool	ft_isspace(char c); // true if white_space - wrong if not.

// ----------------------------------------------------------------------
//							FORMAT_TXTR
// ----------------------------------------------------------------------

char	*init_str(char *line, char *str, int len, int i); // reallocates formatted lines-string (without spaces) - inits the string so it has this format eg.: "NO ./pngs/wall_1.png" - returns it to cut_spaces - returns it to init_txtrs where data.txtrs will be initialised with this output.
int		init_txtrs(t_configs *data); // goes through first 6 lines of data.lines and cuts the spaces off the lines by calling cut_spaces() - initialises data.txtrs array with filtered white spaces lines.
char	*cut_spaces(char *line); // cuts all before first 2 chars - skips chars - cuts spaces afterwards - calls init_str().

// ----------------------------------------------------------------------
//							CHECK_TEXTURES
// ----------------------------------------------------------------------

// at this point data.txtrs array contains the correctly formatted input components line NO, EA, F, C, ... so now paths and colors can properly be checked - if they're valid they will be put into the data.textures array which contains the according MLX variables and color codes (if textures are valid they will be mlx_load_png() and put into the struct).

char		*get_path(char *str); // cuts the txtrs line which it gets to only the path and returns the cut string - for both color code and texture/ (png)-path.
int			str_isdigit(char *str); // checks seperate part of the color code - only one 'number' - if there is a char return (error); if 'number' is more than 3 digits return (error); if more than 'number' is out of int range return (error); is being called for every 'number' of the color code.
uint32_t	set_color(char **d); // converts WHOLE color code 'into uint_32_t color' variable - iterates through char **d (the seperate parts of the color code) and adds and shifts bits into uint32_t variable - setting brightness of the colors to 255. (explanation of the bit shifting under function in file).
int			process_color(t_configs *data, char *path, char which); // gc_split on color code with ',' delimiter - (cahr **d = output of gc_split) - iterates through d, if ( d[i] empty ) return error - calls str_isdigit() on every string - if there are != 3 'numbers' (strings) in char **d array, return (error) - calls set_color() for either floor or ceiling color code.
int			check_textures(t_configs *data, int i, char *path, int error); // allocates data.textures (<-!STRUCT!) in gc TEXT list - goes through txtrs and calls get_path() on every line and saves in seperate path pointer - if a color, it calls process_color() - if a texture, calls process_texture() - p._color() and p._texture() both return indicator which will be checked at the end of error code.

// ----------------------------------------------------------------------
//							INIT_MAP
// ----------------------------------------------------------------------

int			process_texture(t_configs *data, char *path, char which); // receives only the path of the different textures and mlx_loads them into according varaible in data.textures struct - STILL NEED TO mlx_delete_texture() AT THE END.

// ----------------------------------------------------------------------
//							INIT_MAP
// ----------------------------------------------------------------------

// so far we have parsed the input configurations into the data.textures struct which will contain only correct components - will be parsed to execution
// now we will put the map in a seperate array 'data.map' and do the checking on this variable cs its easier to have seperate map variable.

void		per_line(t_configs *data, char *line, int i, int len); // gets called for every line of the map and if an empty line (END OF MAP) returns - also counts the longest line from the map - recognises '\t' and adds 4 (cs 1 '\t' is 4 ' ' (spaces) later - important for converting later in init_map()) - also inits data.m_hight (map_hight) and data.m_width (map_width - with the longest line counted).
int			allocate_map(t_configs *data, int i); // alloactes char **data.map array with data.m_hight and allocates each single line with data.m_width + 1 - all with GC MAP-list.
int			init_map_helper(t_configs *data, int i, int j); // subsitutes 1 '\t' with 4 ' ' (spaces).
void		init_map(t_configs *data, int i, int j, int l); // copies the lines that contain the map from data.lines into data.map - if at the end of a line and index is not yet at data.m_with, it will fill with spaces - if '\t' it calls init_map_helper(), which convertes 1 '\t' to 4 ' ' (spaces) - sets '\0' at end of every line in data.map array.
int			create_map(t_configs *data); // goes through data.lines array from line 6 on (where the map alwalys starts) calls per_line() for each line - calls allocate_map() afterwards - init_map() after - player() after - set_up_fl() after.

// ----------------------------------------------------------------------
//							INIT_MAP
// ----------------------------------------------------------------------

int			check_map(t_configs *data, char **map); // iterates through data.map and checks on crucial map components (also 'D' for doors - bonus) - if 'D' calls check_doors().

// ----------------------------------------------------------------------
//								PLAYER
// ----------------------------------------------------------------------

// here we check if the player components in the map are valid or not - additionally I allocate 't_map data.map_info' struct, which will contrain all crucial information about the player and the map; X, Y position of player; starting direction; map array, map hight, map width - so you can work only with this and the data.textures struct
// those 2 struct contain all the information that is important for you.

int			get_player(t_configs *data, int i, int j, char c); // can only be called ONCE, if more times, then there are too many players and return (error) - allocates data.map_info struct; gets player_pos (X, Y) already converted to float and + 0.5 so player will be in the middle of the block; gets the direction in which the player will start; gets width, hight of the map AND data.map_info.map = data.map - the map itself.
int			player(t_configs *data); // iterates through data.map and checks for player starting position/direction (N, W, S, E) - if found calls get_player().

// ----------------------------------------------------------------------
//								FLOOD_FILL
// ----------------------------------------------------------------------

int			flood_fill(t_configs *data, int y, int x, char **map); // goes through the map recursivly; updates the position with every function call; overwrites the current position with 'F' character - until it reaches final '1' or 'F'
int			set_up_fl(t_configs *data); // allocates subst map array in GC PARS-list and inits it - we use this for flood_fill checking - calls flood_fill with according X and Y of the player.

// ----------------------------------------------------------------------
//								 BONUS
// ----------------------------------------------------------------------

int			check_doors(t_configs *data, char **map, int i, int j); // checks if the door is put at valid spot; a door can stand only between 2 Walls; either there are walls over and under the door or on the left and the right of the door, so the door cant stand alone or attached to only 1 wall.

// this was the whole parsing
// the GC uses 4 seperate lists: 
//	PARS: with this list we allocate only variables that we use as tools for the parsing - WILL BE FREED AFTER THE PARSING PART
//	MAP: in this list we I store the struct of the map struct that is neccessary creating the map in execution - FREE AFTER EXECUTION
//	TEXT: we store mlx varibles that we need to delete after game end - WILL BE FREED AFTER EXECUTION
//	EXEC: we store utility variables that we need for the execution - WILL BE FREED AFTER EXECUTION

// SO if you need to allocate something you can just use gc_malloc(size_t size, int id) - the size like regularly in malloc() and the id for which list you want to store the variable in ( in your case 'EXEC'; you can see the enums in the gc.h)

#endif