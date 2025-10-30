#include "../cubed.h"

int	validate_args(int ac, char **av)
{
	char	*format;

	if (ac != 2)
		return (0);
	format = ft_strrchr(av[1], '.');
	if (!format || ft_strncmp(format, ".cub", 4) != 0 || format[4] != '\0')
		return (0);
	return (1);
}

void	init_struct(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	game->ceiling_color = -1;
	game->floor_color = -1;
}

// int main(int ac, char **av)
// {
// 	t_game game;

// 	if (!validate_args(ac, av))
// 		return (printf("Invalid arguments. Try again\n"), 1);	
// 	init_struct(&game);
// 	if (!parse_file(av[1], &game))
// 		return (printf("Error with parsing\n"), 1);
// }