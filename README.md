# so_long | slucas-s

Prior to starting with this project, it’s better to learn about the miniLibX, the simple graphic library that we use at 42. Luckily I have a sample project where I a talk about how it works and what it offers [here](https://github.com/S-LucasSerrano/miniLibX_sample):
https://github.com/S-LucasSerrano/miniLibX_sample

The aim of this project is to create a small 2D game where players have to pick up all collectables and go to the exit making as few moves as possible. In my case, the game is about a muscular gardener cleaning up her garden from weeds. While ¿alien? creatures stand in her way. Because they are on mars. Or something.

![gif_01](https://drive.google.com/uc?export=view&id=1lHOYdkrSTlfExwcKfGCXHiamJJIL0q9h)

### Index
---
* [How to play](#How-to-play)
* [Tile map](#Tile-map)
* [Player and Input](#Player-and-Input)
* [Enemies](#Enemy-Behaviour)
* [Animation](#Render,-Animation-and-VFX)
* [Structs and Data](#Structs-and-Data)


### How to play
---
###### Maps
The game is able to play any map you want as long as it follow some specific rules:
* The map has to be a ``.ber`` file.
* It can only contain some of the following characters:

| Character | Object |
| - | - |
| 1 | Wall. |
| 0 | Empty space. |
| C | Collectable. |
| E | Exit. |
| P | Player starting position. |
| H | Horizontal enemy. It moves to left and right, changing direction when its path is blocked. |
| V | Vertical enemy. Moving up and down. |
| F | Following enemy. Each move tries to get closer to the player |

* The map must be a rectangle surrounded by walls ‘1’.
* It must have at least one exit ‘E’ and one collectable ‘C’. And only one player ‘P’.

See some examples in the ``map_files`` folder of this project.

###### Controls
Use ``WASD`` to move. You move one tile at a time. Enemies move after you do, also one tile at a time, and will kill you when you move into their tile or they move into yours. After picking up all weeds, the exits open and you may leave to see how many moves you’ve used to solve the map.

You can restart the game with ``R``, or close it with ``esc``.

![gif_02](https://drive.google.com/uc?export=view&id=13aqJkX7vRyEvr9REWksoYbGFq_Y33oi-)

###### Execute the game
To play you can use some of the makefile rules, or execute the file _so_long.out_ if it's been generated, passing the map you want to play as parameter (``./so_long.out mapFileToPlay.ber``). The make file has the following rules:

| Rule | Function |
| - | - |
| ``make`` | Generates _so_long.out_ and an object file for each .c. |
| ``make clean`` | Deletes all object files. |
| ``make fclean`` | Deletes the object files and the _so_long.out_. |
| ``make re`` | makes ``fclean`` and ``make`` again. |
| ``make exe m=mapFileToPlay.ber`` | Doeas ``make`` and runs the game with the selected map. |
| `` make play`` | Allows you to play some of the maps I designed in a defined succession. To play the next map just press ``esc``. |


### Code
---
First, I check if the program is receiving any parameter, and if the parameter is the correct type of file. If there is more than one parameter I print a warning to make sure that the user knows that only the first one will be used. If the file is valid I read it, ending up with a 2D char table (``char **``). Checking then if that table follows the above rules. When I found something wrong, like an invalid character, a line with different length or more that one player, I print an error message and turn a boolean _valid_map_ to false, so the whole map is checked and all errors within it are printed in one run instead of just returning with the first error found. If the map is invalid, I free the char table and end the program.

#### Tile map
But if it follows the rules, I then allocate memory for a 2D _t_tile_ table. A struct that I’ve defined with the following info:
````c
typedef struct s_tile
{
	t_tiletype	type;
	t_tiletype	og_type;
	t_vector	position;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;
````
* The ``type`` can be: EMPTY, WALL, COLLECTABLE, EXIT, PLAYER, ENEMY or FOLLOWER.
* The ``og_type``, original type, is used to reset the game.
* ``Position`` defines the pixel coordinates of the tile to be drawn in the window. All my sprites are 64x64 pixels. So the position of each tile is its coordinates in the table x 64.
* And finally, I have pointers to the adjacent tile in every direction.

I follow the ``char **`` map in parallel to the ``t_tile **`` one. Setting each tile’s type, position and neighbours. When a collectable is found, I add one to the collectables counter. When I find an enemy, I add a new enemy to an enemy list. And when I find the player, I set it up with the corresponding tile. More on that next.

At the end, I have a ``t_tile **`` table with each tile filled with its type, position, and adjacent tiles. With the columns ending in a NULL pointer, and each row with a tile of type 0. As well as the player, enemies and collectables all setup. So the only thing that's left, is initializing the miniLibX, opening the window with the same size as the map, and hooking your functions to the corresponding events.

#### Player and Input
Hooked to the key pressed event is a function called ``input``. It has some ifs to check what key has been pressed. If it was some of the ``WASD`` it calls a function to move the player. When ``R``, to reset the game. And with ``esc`` it ends the program. The functions that moves the player returns TRUE or FALSE if the movement was successfully done, if so, we add one to the *moves* counter. Only moving and picking a collectable add to the counter.

The player is defined by its own struct.
````c
typedef struct s_player
{
	t_tile	*tile;
	void	*current_img;
	int	framecount;
	int	idle_frames;
	void	*idle_img_0;
	void	*idle_img_1;
	int	action_frames;
	void	*action_img;
}	t_player;
````
With a pointer to the tile that the player is currently in. The rest of it is for animation, which I will talk about later. So if the player moves, for example, to the right. I go to its tile, which has a pointer to the one on the right.
* if it is a **wall**, you just don’t move and don’t add anything to the moves counter.
* If its type is an **empty** space, I set the player tile pointer to the new one, the new tile as player type and the old one as empty.
* If it is a **collectable** we set it as an empty, play the action animation, and reduce the collectables counter by one.
* If it’s an **enemy** (enemy or follower tile type), the player is killed by setting his current tile type to empty, and his pointer to NULL.
* And finally, if it’s an **exit** and collectables are set to 0, we... kind of also kill the player setting his tile to NULL. But also putting the collectable counter to -1 so the render function knows to draw the _moves_ counter in a different color. When the player’s tile is NULL, only _esc_ or _reset_ are accepted as input.

#### Enemy behaviour
Every time that an enemy is found while generating the tile map, an enemy is added to a list. With each node having info about the type of enemy (HORIZONTAL, VERTICAL or FOLLOWER), his current direction that can be 0 or 1 and pointers to his current and original tile, and the next enemy of the list.
````c
typedef struct s_enemy
{
	t_enemyytpe	type;
	int		dir;
	t_tile		*og_tile;
	t_tile		*tile;
	struct s_enemy	*next;
}	t_enemy;
````
Every time the player spends a turn, by moving or picking a collectable, I go through the list moving each enemy as it corresponds to his type:
| Enemy type | Behaviour |
| - | - |
| Vertical and Horizontal | They move left or right / up or down depending on their current direction. Because every enemy has a pointer to his tile, we can go, to move up for example, to the up pointer of their current tile and check if it is blocked or not. An enemy will only move into a tile if its type is EMPTY or PLAYER. Killing him if that is the case. Meaning that collectables and other enemies can block their way. If they can't move to the next tile in their current direction, they change it by spending one turn without moving. |
| Follower | We first calculate his distance to the player in both axes, to try to move him in the  axis that is closer to him. After making ``enemy_position - player_position`` we know that if the value is negative the player is on the left, and if it’s positive it is on the right. And the same with up and down. Knowing in which direction the enemy needs to move. But if the tile in that direction is blocked, the enemy will try to get closer to the player in the other axis. So this enemy can be tricked to get stuck on a corner. |

![gif_03](https://drive.google.com/uc?export=view&id=1BtgX7zSWJkOj_RySpeqUsVakeiolUCao)

#### Render, Animation and VFX
Hooked to the loop is the ``update`` function. Which is called once per frame. Then, the current image of each animated sprite is calculated. For **idles** I have an ``animation_frames`` variable that defines how many frames last each image of the cycle. I have the ``current_image``, a pointer to the image that currently will be drawn, pointers to the two images of the animation cycle, and a ``counter`` that can be either an int in a struct or a static variable within a function if that value is not needed outside of that function. The counter adds one each frame until it reaches the animation frames, changing the current image.
````c
void	calculate_idle_animation (idle_animation)
{
	static int counter;

	counter++;
	if (counter == idle_animation->frames)
		idle_animation->current_img = idle_animation->img_0;
	else if  (counter >= idle_animation->frames * 2)
	{
		idle_animation->current_img = idle_animation->img_1;
		counter = 0;
	}
}
````

For the **particles-like effect** that I use when you pick up objects, die or close the door, I use something similar. But with only one image, and a ``position`` to draw the effect on. When I want to play the effect I set a new position, and reset the counter to 0. Adding one each frame, and only drawing the image if the counter is less than the animation frames.

Finally, for the **action pose** that the player does when picking up the weeds. I change the current image of the player to the action one, and reset the frames counter. Adding an extra condition above the two that change back and forward between the sprites of the idle. Checking if the current image is set to be the action image and if the counter is less than the action animation frames. Not letting the rest of the code run if that is not the case.
````c
counter++;
if(current_img == action_img && counter < action_frames)
	return ;
// al the idle code
````

After making all these calculations, adding to all the counters and changing the current images if necessary, I call the ``render`` function. A function that clears the window and loops through each tile drawing the image that corresponds to its type. For the **walls**, because I know that the map will always be surrounded by them, I have some extra tileable sprites to make a cool frame around the window. Having nine different images for the walls. The normal one that will be drawn in the middle of the map, one for the top, the bottom, left and right, and one for each of the corners.

Finally, I have some extra **flashes** or vfx effects that I can draw for one frame to make some actions have a little more game feel to them. I called them ``panels``. They are basically two plain images with the same size as the window. I have a white one for when you reach the exit or reset the game. And a red one for when an enemy kills you.

#### Structs and Data
I save all this data needed for the game to work in structs that I pass to each function as needed.
````c
typedef struct s_game
{
	void		*mlx;		// pointer to the mlx
	void		*window;	// pointer to the window
	t_vector	wndw_size;	// window size

	t_tile		**tilemap;	// 2D tile table

	t_player	player;		// struct with info about the player: current tile, animation frames, counter and images

	int		og_collects;	// original collectable to be able to reset
	int		collects;	// current value, reducing one each time you pick up one
	int		moves;		// moves counter, adding one each time you spend a turn

	t_enemy		*enemy_list;	// list of enemy structs
	
	// sprites/images
	t_vector	img_size;
	t_wall_img	wall_imgs;	// struct with all nine wall images
	t_collect_img	collects_imgs;	// struct with info about the collectables animation.
	t_enemy_img	enemy_imgs;	// struct with the animation info of the two type of enemies
	void		*door_open_img;	// images for the door
	void		*door_close_img;
	t_effect	effect;		// struct with the particle effect animation
	void		*red_panel;	// panels
	void		*white_panel;

}	t_game;
````

![gif_04](https://drive.google.com/uc?export=view&id=1VDS3PbZLJ1wkZcaZaGOaA4SBIrQME07d)

### Contact
---
Feel free to clone this project, check the code or contact me if you want or find something wrong or missing in this documentation.

* 42 Login:	*slucas-s*
* Email:		*Lucas.ss.Serrano@Gmail.com*

Good luck with your projects!
