#include "../so_long.h"

void	start_effect(t_effect *effect, t_vector pos)
{
	effect->counter = 0;
	effect->pos = pos;
}

t_bool	move_to(t_game *game, t_tile *tile)
{
	if (tile->type == EMPTY)
	{
		tile->type = PLAYER;
		if (game->player.tile->type != EXIT)
			game->player.tile->type = EMPTY;
		game->player.tile = tile;
	}
	else if (tile->type == COLLECTABLE)
	{
		tile->type = EMPTY;
		game->collects--;
		start_effect(&game->effect, tile->position);
		game->player.framecount = 0;
		game->player.current_img = game->player.action_img;
	}
	else if (tile->type == EXIT && game->collects <= 0)
	{
		start_effect(&game->effect, tile->position);
		game->player.tile->type = EMPTY;
		game->player.tile = NULL;
		game->collects = -1;
	}
	else
		return (FALSE);
	return (TRUE);
}

/* Input management */
int	input(int key, t_game *game)
{
	t_bool	moved;

	if (key == ESC)
		end_program(game);
	if (game->player.tile == NULL)
		return (0);
	if (key == KEY_UP)
		moved = move_to(game, game->player.tile->up);
	else if (key == KEY_DOWN)
		moved = move_to(game, game->player.tile->down);
	else if (key == KEY_LEFT)
		moved = move_to(game, game->player.tile->left);
	else if (key == KEY_RIGHT)
		moved = move_to(game, game->player.tile->right);
	else
		return (0);
	if (moved)
		printf("Moves -> %02d\n", ++game->moves);
	return (1);
}
