#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct s_setup
{
	char	**lines;
	int		lcount;
}	t_setup;

// ----------------------------------------------------------------------
//							  MAIN
// ----------------------------------------------------------------------

int		main(int argc, char **argv);
void	init_data(t_setup *data);

#endif