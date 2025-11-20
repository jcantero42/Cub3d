/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:11:35 by marcolop          #+#    #+#             */
/*   Updated: 2025/11/20 11:11:36 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	update_game(int keycode, t_game *g)
{
	if (keycode == KEY_W)
		move_player(g, keycode);
	else if (keycode == KEY_A)
		move_player(g, keycode);
	else if (keycode == KEY_S)
		move_player(g, keycode);
	else if (keycode == KEY_D)
		move_player(g, keycode);
	else if (keycode == KEY_RIGHT)
		rotate_perspective(g, keycode);
	else if (keycode == KEY_LEFT)
		rotate_perspective(g, keycode);
	else if (keycode == KEY_ESC)
		terminate(g);
	return (0);
}
