#include "cubed.h"

void	print_map(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->height)
	{
		printf("%s\n", g->map[i]);
		i++;
	}
}
