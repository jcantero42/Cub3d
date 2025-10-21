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

	double	player_x;
	double	player_y;
	double	angle;

	int		right;
	int		left;
	int		up;
	int		down;

	double	delta_x;
	double	delta_y;

	double	hor_x;
	double	hor_y;

	double	ver_x;
	double	ver_y;

	double	step_x;
	double	step_y;

	void	*mlx;
	void	*win;
} t_game;

