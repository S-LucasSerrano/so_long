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

t_bool	start(t_game *game, int argc, char **argv)
{
	game->collects = 0;
	game->moves = 0;
	game->player.idle_frames = 17;
	game->player.action_frames = 10;
	game->collects_imgs.anim_frames = 25;
	game->effect.frames = 7;
	game->tilemap = map_init(argc, argv, game);
	if (game->tilemap == NULL)
		return (FALSE);
	game_init(game);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (!start(&game, argc, argv))
		return (0);
	mlx_hook(game.window, 2, 0, *input, (void *)&game);
	mlx_loop_hook(game.mlx, update, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
