#include "../so_long.h"

static void	open_wallimgs_up(t_game *game)
{
	game->wall_imgs.block = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall_02.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.up_left = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall_ul.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.up = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall_u.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.up_right = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall_ur.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.right = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall_r.xpm",
			&game->img_size.x, &game->img_size.y);
}

static void	open_wallimgs_down(t_game *game)
{
	game->wall_imgs.down_right = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall_dr.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.down = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall_d.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.down_left = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall_dl.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.left = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall_l.xpm",
			&game->img_size.x, &game->img_size.y);
}

static void	open_player_imgs(t_game *game)
{
	game->player.idle_img_0 = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_01.xpm", &game->img_size.x, &game->img_size.y);
	game->player.idle_img_1 = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_02.xpm", &game->img_size.x, &game->img_size.y);
	game->player.action_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_03.xpm", &game->img_size.x, &game->img_size.y);
	game->player.current_img = game->player.action_img;
}

static void	open_collect_imgs(t_game *game)
{
	game->collects_imgs.img_0 = mlx_xpm_file_to_image(game->mlx,
			"sprites/plant_03.xpm",
			&game->img_size.x, &game->img_size.y);
	game->collects_imgs.img_1 = mlx_xpm_file_to_image(game->mlx,
			"sprites/plant_04.xpm",
			&game->img_size.x, &game->img_size.y);
	game->collects_imgs.current_img = game->collects_imgs.img_0;
	game->effect.img = mlx_xpm_file_to_image(game->mlx,
			"sprites/effect_w.xpm",
			&game->img_size.x, &game->img_size.y);
}

void	open_images(t_game *game)
{
	open_wallimgs_up (game);
	open_wallimgs_down (game);
	open_player_imgs(game);
	open_collect_imgs(game);
	game->door_open_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/door_01.xpm",
			&game->img_size.x, &game->img_size.y);
	game->door_close_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/door_02.xpm",
			&game->img_size.x, &game->img_size.y);
}
