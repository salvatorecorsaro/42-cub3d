/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <scorsaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:30:03 by scorsaro          #+#    #+#             */
/*   Updated: 2020/10/01 20:01:53 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_press(int keycode, t_move *move)
{
	if (keycode == ESC)
		move->esc = TRUE;
	else if (keycode == FORWARD)
		move->foward = TRUE;
	else if (keycode == BACK)
		move->back = TRUE;
	else if (keycode == LEFT)
		move->left = TRUE;
	else if (keycode == RIGHT)
		move->right = TRUE;
	else if (keycode == TURNLEFT)
		move->turn_left = TRUE;
	else if (keycode == TURNRIGHT)
		move->turn_right = TRUE;
	else if (keycode == SPRINT)
		move->movement_speed = 0.1;
	return (0);
}

int	ft_release(int keycode, t_move *move)
{
	if (keycode == ESC)
		move->esc = FALSE;
	else if (keycode == FORWARD)
		move->foward = FALSE;
	else if (keycode == BACK)
		move->back = FALSE;
	else if (keycode == LEFT)
		move->left = FALSE;
	else if (keycode == RIGHT)
		move->right = FALSE;
	else if (keycode == TURNLEFT)
		move->turn_left = FALSE;
	else if (keycode == TURNRIGHT)
		move->turn_right = FALSE;
	else if (keycode == SPRINT)
		move->movement_speed = 0;
	return (0);
}
