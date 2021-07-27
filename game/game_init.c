#include "../so_long.h"
#include "../map/map.h"

void	open_images(t_game *game);

/* Creates -with malloc- a tilemap acording to the
first file of argv. Returns NULL if an error occurs. */
t_tile	**map_init(int argc, char **argv, t_game *game)
{
	char	**map;
	t_tile	**tilemap;

	if (!valid_file(argc, argv[1]))
		return (NULL);
	map = read_map (argv[1]);
	if (!map)
		return (NULL);
	if (valid_map(map) == FALSE)
	{
		ft_free_chartable(map);
		return (NULL);
	}
	tilemap = generate_tilemap(map, game);
	ft_free_chartable(map);
	if (!tilemap)
		return (NULL);
	return (tilemap);
}

/* Starts the mlx, opens a window, and open images */
void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			game->wndw_size.x + IMG_SIZE / 2,
			game->wndw_size.y,
			"so_long");
	mlx_hook(game->window, 17, 0, end_program, game);
	open_images(game);
	game->white_panel = new_panel(game, new_color(254, 254, 254, 0));
	game->red_panel = new_panel(game, new_color(197, 4, 4, 0));
}
