#include "../inc/cub3d.h"

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

int main(int ac, char **av)
{
	t_game game;

	if (!validate_args(ac, av))
		return (1);	
	ft_memset(&game, 0, sizeof(t_game));
	if (!parse_file(av[1], &game))
		return (1);
}