#ifndef CUBED_H
# define CUBED_H

#define WIN_WIDTH 640
#define WIN_HEIGHT 480

#define FOV 1.152

#define PI 3.14159265359

#define KEYPRESS 2

#define KEY_ESC 65307

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100

#define KEY_LEFT 65361
#define KEY_RIGHT 65363

#define PLAYER_STEP 0.05

#define PLAYER_BARRIER 0.5

#define ON_DESTROY 17

typedef struct s_game
{
	char	*no_texture;
	char	*so_texture;
	char	*ea_texture;
	char	*we_texture;

	int		floor_color;
	int		ceiling_color;

	char	**map;
	int		width;
	int		height;

	double	px; // player x
	double	py; // player y
	
	double	pa; // player angle
	double	ra; // ray angle

	int		right;
	int		left;
	int		up;
	int		down;

	double	dx; // delta x
	double	dy; // delta y

	double	hx; // horizontal x
	double	hy; // horizontal y

	double	vx; // vertical x
	double	vy; // vertical y

	double	step_x;
	double	step_y;
	double	sa; // step angle

	double	fx; // final x
	double	fy; // final y

	double	dh; // distance horizontal
	double	dv; // distance vertical

	double	dmin; // distance minimum

	double	h; // height of wall
	
	double	nx; // new x
	double	ny; // new y
	double	ma; // move angle
	double	npx; // new player x
	double	npy; // new player y
	
	double	ds; // distance screen

	void	*mlx;
	void	*win;

	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
} t_game;

void	pixel_put(t_game *g, int x, int y, int color);
void	paint_column(t_game *g, int x, int h);

char	**init_map();
t_game	*init_game();
char	check_vertical(t_game *g);
char	check_horizontal(t_game *g);
void	cast_rays(t_game *g);
int	update_game(int keycode, t_game *g);
int	terminate(t_game *g);
void	move_player(t_game *g, int keycode);

#endif
