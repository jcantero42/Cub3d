#ifndef CUB3D_H
# define CUB3D_H

#include "../libft/libft.h"
#include <stdio.h>
#include <fcntl.h>



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
	char	*map;
	int		width;
	int		height;
} t_game;

int		validate_args(int ac, char **av);
int		parse_file(char *filename, t_game *game);
int		parse_config_line(char *line, t_game *game);
int		config_is_complete(t_game *game);
int 	ft_strcmp(const char *s1, const char *s2);








#endif