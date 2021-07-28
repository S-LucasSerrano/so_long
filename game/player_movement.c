#include "../so_long.h"

void	move_to_empty(t_game *game, t_tile *tile)
{
	tile->type = PLAYER;
	if (game->player.tile->type != EXIT)
		game->player.tile->type = EMPTY;
	game->player.tile = tile;
}

void	pick_collect(t_game *game, t_tile *tile)
{
	tile->type = EMPTY;
	game->collects--;
	effect_anim(&game->effect, tile->position);
	action_anim(&game->player);
}

void	move_to_exit(t_game *game, t_tile *tile)
{
	effect_anim(&game->effect, tile->position);
	mlx_put_image_to_window(game->mlx, game->window, game->white_panel, 0, 0);
	remove_player(game);
	game->collects = -1;
}

void	move_to_enemy(t_game *game, t_tile *tile)
{
	remove_player(game);
	effect_anim(&game->effect, tile->position);
	mlx_put_image_to_window(game->mlx, game->window, game->red_panel, 0, 0);
}
