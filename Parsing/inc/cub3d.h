#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "../gc/gc.h"
#include <MLX42/MLX42.h>
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

typedef struct s_textures
{
	//textures
	mlx_texture_t	*no_text;
	mlx_texture_t	*so_text;
	mlx_texture_t	*we_text;
	mlx_texture_t	*ea_text;

	//floor/ceeling
	uint32_t	f_clr;
	uint32_t	c_clr;
}	t_textures;

typedef struct s_map
{
	int		hight;
	int		width;
	char	**map;

	//player position 
	float		x_pos;
	float		y_pos;
	char		plr_dir;
}	t_map;

typedef struct s_configs
{
	char		**lines;
	int			lcount;
	char		**txtrs;
	t_textures	*textures;
	int			where_color_is;

	//map
	int		m_hight;
	int		m_width;
	char	**map;
	t_map	*map_info;
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

int		main(int argc, char **argv);
void	init_data(t_configs *data);
int		get_lines(char *argv1, t_configs *data);
int		correct_name(char *argv1);
bool	check_empty_line(char *line);

int		set_flags(t_seen *flags);
int		check_duplicate(char **lines);
int		seperate(t_configs *data);
int		init_txtrs(t_configs *data);//char **txtrs kann ich das machen?
char	*cut_spaces(char *line);
char	*init_str(char *line, char *str, int len, int i);
int		check_textures(t_configs *data, int i, char *path, int error);
bool	ft_isspace(char c);
int		create_map(t_configs *data);

int		check_map(t_configs *data, char **map);
void	init_map(t_configs *data, int i, int j, int l);

int	get_player(t_configs *data, int i, int j, char c);
int	player(t_configs *data);

int	set_up_fl(t_configs *data);

#endif