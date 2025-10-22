#ifndef CUBED_H
# define CUBED_H

#define WIN_WIDTH 640
#define WIN_HEIGHT 480

#define FOV 1.152

#define PI 3.14159265359

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

	double	fx; // final x
	double	fy; // final y

	double	dh; // distance horizontal
	double	dv; // distance vertical

	double	dmin; // distance minimum

	double	h; // height of wall

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

#endif
