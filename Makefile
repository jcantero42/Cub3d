NAME = cub3D

SRC = main.c paint.c check.c game.c raycast.c

OBJS = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

libft/libft.a:
	$(MAKE) -C libft

mlx_linux/libmlx_Linux.a:
	$(MAKE) -C mlx_linux

$(NAME): libft/libft.a mlx_linux/libmlx_Linux.a $(OBJS)
	$(CC) $(CFLAGS)  $^ -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft -lft -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C mlx_linux
	$(MAKE) clean -C libft

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)
	$(MAKE) clean -C mlx_linux
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re
