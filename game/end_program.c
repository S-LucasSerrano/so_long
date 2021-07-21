#include "../so_long.h"

void	free_tilemap(void)
{
	printf("\033[31;3m WARNING: \033[37m I am NOT freeing the tilemap\n \033[0m");
}

int	end_program(t_game *game)
{
	free_tilemap();
	game->tilemap = NULL;
	exit(0);
}
