#include "basics.h"
#include "map/map.h"
#include "so_long.h"

void	print_tilemap(t_tile **tilemap)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (tilemap[y] != NULL)
	{
		x = 0;
		while (tilemap[y][x].type != 0)
		{
			printf ("%c ", tilemap[y][x].type);
			x++;
		}
		printf ("\n");
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (!start(&game, argc, argv))
		return (0);
	mlx_hook(game.window, 2, 0, input, (void *)&game);
	mlx_loop_hook(game.mlx, update, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
