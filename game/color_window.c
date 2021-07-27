#include "../so_long.h"

void	color_window(t_game *game, int color)
{
	int x;
	int y;

	y = 0;
	while(y < game->wndw_size.y)
	{
		x = 0;
		while (x < game->wndw_size.x)
		{
			mlx_pixel_put(game->mlx, game->window, x, y, color);
			x++;
		}
		y++;
	}
}
