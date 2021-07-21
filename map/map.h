#ifndef MAP_H
# define MAP_H

# include "../basics.h"

int		valid_file(int argc, char *file);
char	**read_map(char *file);
int		valid_map(char **map);

typedef struct s_mapcheckerdata
{
	t_vector	size;
	t_vector	point;
	t_bool		b_player;
	t_bool		b_exit;
	t_bool		b_collect;
}				t_mapcheckerdata;

#endif
