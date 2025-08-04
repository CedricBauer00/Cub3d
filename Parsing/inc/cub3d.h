#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

typedef struct s_configs
{
	char	**lines;
	int		lcount;

	//textures
	char	*no_text;
	char	*so_text;
	char	*we_text;
	char	*ea_text;

	//floor/ceeling
	int		f_clr;
	int		c_clr;

	//map
	int		m_hight;
	int		m_width;
	char	**map;

	//player position 
	int		x_pos;
	int		y_pos;
	char	plr_dir;
}	t_configs;

// ----------------------------------------------------------------------
//							  MAIN
// ----------------------------------------------------------------------

int		main(int argc, char **argv);
void	init_data(t_configs *data);
int		correct_name(char **argv);

#endif