#include "../so_long.h"

static void	player_animation(t_player *player)
{
	if (player->current_img == player->action_img
		&& player->framecount >= player->action_frames)
	{
		player->current_img = player->idle_img_1;
	}
	else if (player->framecount == player->idle_frames)
	{
		player->current_img = player->idle_img_0;
	}
	else if (player->framecount >= player->idle_frames * 2)
	{
		player->current_img = player->idle_img_1;
		player->framecount = 0;
	}
	player->framecount += 1;
}

static void	collec_animation(t_collect_img *img)
{
	static int	frame;

	if (img->anim_frames == 0)
		return ;
	if (frame == img->anim_frames)
	{
		img->current_img = img->img_0;
	}
	else if (frame >= img->anim_frames * 2)
	{
		img->current_img = img->img_1;
		frame = 0;
	}
	frame += 1;
}

static void	effect_animation(t_effect *effect)
{
	if (effect->counter < effect->frames)
		effect->counter++;
}

static void	enemy_animation(t_enemy_img *img)
{
	static int	counter;

	if (counter == img->anim_frames)
		img->current = img->img_01;
	else if (counter > img->anim_frames * 2)
	{
		img->current = img->img_02;
		counter = 0;
	}
	counter++;
}

int	update(t_game *game)
{
	player_animation(&game->player);
	collec_animation(&game->collects_imgs);
	effect_animation(&game->effect);
	enemy_animation(&game->enemy_imgs);
	render(*game);
	return (1);
}
