#ifndef SO_LONG_H
# define SO_LONG_H

# include "basics.h"
# include "mlx.h"

/* Size of every sprite */
# define IMG_SIZE 64

// ---------- TILES

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E'
}	t_tiletype;

typedef struct s_tile
{
	t_tiletype		type;
	t_vector		position;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

// ---------- IMAGES

/* All posible wall images */
typedef struct s_wall_img
{
	void	*block;
	void	*up_left;
	void	*up;
	void	*up_right;
	void	*right;
	void	*down_right;
	void	*down;
	void	*down_left;
	void	*left;
}	t_wall_img;

/* Collectables animation info */
typedef struct s_coll_img
{
	void	*current_img;
	int		anim_frames;
	void	*img_0;
	void	*img_1;
}	t_collect_img;

/* Info for the effect after collecting something */
typedef struct s_effect
{
	void		*img;
	t_vector	pos;
	int			frames;
	int			counter;
}	t_effect;

// ---------- GAME

/* All valid input keys */
enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	ESC = 53
};

/* Info about the player */
typedef struct s_player
{
	t_tile	*tile;
	void	*current_img;
	int		framecount;
	int		idle_frames;
	void	*idle_img_0;
	void	*idle_img_1;
	int		action_frames;
	void	*action_img;
}	t_player;

/* All info for the game run */
typedef struct s_game
{
	void			*mlx;
	void			*window;
	t_vector		wndw_size;
	t_tile			**tilemap;
	t_player		player;
	int				collects;
	int				moves;
	t_vector		img_size;
	t_wall_img		wall_imgs;
	t_collect_img	collects_imgs;
	void			*door_open_img;
	void			*door_close_img;
	t_effect		effect;
}	t_game;

// ---------------------------
// FUNCTIONS

t_tile	**map_init(int argc, char **argv, t_game *game);
t_tile	**generate_tilemap(char **map, t_game *game);
void	game_init(t_game *game);

int		input(int key, t_game *game);
int		update(t_game *game);
void	render(t_game game);

int		end_program(t_game *game);

#endif