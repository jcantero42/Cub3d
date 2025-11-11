#include "cubed.h"
#include "libft/libft.h"

void	time_diff(t_game *g)
{
	gettimeofday(&g->now, NULL);
	g->ms = (g->now.tv_sec - g->then.tv_sec) * 1000;
	g->ms += (g->now.tv_usec - g->then.tv_usec) / 1000;
	ft_memcpy(&g->then, &g->now, sizeof(g->now));
	// printf("fps: %lf\n", 1 / ((double)g->ms / 1000));
}
