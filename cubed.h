typedef struct s_game
{
	char	*no_texture;
	char	*so_texture;
	char	*ea_texture;
	char	*we_texture;
	int		floor_color;
	int		ceiling_color;
	double	player_x;
	double	player_y;
	char	**map;
	int		width;
	int		height;

	void	*mlx;
	void	*win;

	double	dir_x;
	double	dir_y;

	double	plane_x;
	double	plane_y;

	double	time;
	double	old_time;
} t_game;

