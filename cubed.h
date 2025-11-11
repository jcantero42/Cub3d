#ifndef CUBED_H
# define CUBED_H

#include "mlx_int.h"
#include "libft/libft.h"
#include <sys/time.h>

#define WIN_WIDTH 640
#define WIN_HEIGHT 480

#define FOV 1.152

#define KEYPRESS 2

#define KEY_ESC 65307

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100

#define KEY_LEFT 65361
#define KEY_RIGHT 65363

#define PLAYER_SPEED 0.008

#define ROTATE_SPEED 0.008

#define PLAYER_BARRIER 0.3

#define ON_DESTROY 17

typedef enum e_dir
{
	NORTH, SOUTH, EAST, WEST,
} t_dir;

typedef struct s_game
{
	char	*no_texture;
	char	*so_texture;
	char	*ea_texture;
	char	*we_texture;

	t_img	*no_img;
	int		no_w;
	int		no_h;

	t_img	*so_img;
	int		so_w;
	int		so_h;

	t_img	*ea_img;
	int		ea_w;
	int		ea_h;

	t_img	*we_img;
	int		we_w;
	int		we_h;

	int		floor_color;
	int		ceiling_color;

	char	**map;
	int		width;
	int		height;

	double	px; // player x
	double	py; // player y
	
	double	pa; // player angle
	t_dir	start_direction;
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
	
	struct timeval	then; // last frame time
	struct timeval	now; // curent frame time
	long		ms; // frame time diff in ms
	
	t_dir	dir;

	void	*mlx;
	void	*win;

	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
} t_game;

void	pixel_put(t_game *g, int x, int y, int color);
int	pixel_get(t_img	*img, int x, int y);
void	paint_column(t_game *g, int x, int h);

char	**init_map();
void	init_game(t_game *g);
char	check_vertical(t_game *g);
char	check_horizontal(t_game *g);
void	cast_rays(t_game *g);
int	update_game(int keycode, t_game *g);
int	terminate(t_game *g);
void	move_player(t_game *g, int keycode);
void	rotate_perspective(t_game *g, int keycode);
void	no_pixel_put(t_game *g, int i, int x);
void	so_pixel_put(t_game *g, int i, int x);
void	ea_pixel_put(t_game *g, int i, int x);
void	we_pixel_put(t_game *g, int i, int x);
void	print_map(t_game *g);
void	time_diff(t_game *g);
int	within_boundaries(t_game *g, int x, int y);
int	walled_map(t_game *g, int x, int y);
void	restore_map(t_game *g, int x, int y);

int	parse_file(char	*filename, t_game *game);
int	parse_config(int fd, t_game *game);
int parse_config_line(char *line, t_game *game);
void free_split(char **split);
int	config_is_complete(t_game *game);
int	config_is_complete(t_game *game);
int ft_strcmp(const char *s1, const char *s2);
int	parse_color(char *color_str);
int	count_split(char **split);
int	parse_map(int fd, t_game *game);
int	create_map(int fd, t_game *game);
int	valid_map(t_game *game);
int	normalize_lines(t_game *game);
char	*create_spaces(int n);
int	is_config_line(char *line);
int	is_empty_line(char *line);
char **list_to_array(t_list *list, t_game *g);
int trim_map_lines(t_game *game);
int	ft_isspace(char c);
void	init_struct(t_game *game);
int	validate_args(int ac, char **av);
int	check_elements(t_game *game);
void	assign_dir_and_pos(t_game *game, int i, int j, int *p_count);
int	parse_color_line(char *value, t_game *game, char type);
int	process_map_line(char *line, t_list **list, int *started);
int	get_max_len(t_game *game);

#endif
