/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <scorsaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:31:18 by scorsaro          #+#    #+#             */
/*   Updated: 2020/10/01 20:32:16 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_move(t_all *s)
{
	s->move.foward == 1 ? move_front_back(s, 0) : 0;
	s->move.back == 1 ? move_front_back(s, 1) : 0;
	s->move.left == 1 ? move_left_right(s, 0) : 0;
	s->move.right == 1 ? move_left_right(s, 1) : 0;
	s->move.turn_left == 1 ? turn_left_right(&s->cub, 0) : 0;
	s->move.turn_right == 1 ? turn_left_right(&s->cub, 1) : 0;
	s->move.esc == 1 ? quit(s) : 0;
	return (0);
}

void	move_front_back(t_all *s, int direction)
{
	t_cub	*cub;
	float	movespeed;

	cub = &s->cub;
	movespeed = MOVE_SPEED + s->move.movement_speed;
	if (direction == 0)
	{
		if (cub->map[(int)(cub->player.x +
		cub->direction.x * (movespeed + 0.1))]
		[(int)cub->player.y] != '1')
			cub->player.x += cub->direction.x * movespeed;
		if (cub->map[(int)cub->player.x][(int)(cub->player.y
		+ cub->direction.y * (movespeed + 0.1))] != '1')
			cub->player.y += cub->direction.y * movespeed;
	}
	else
	{
		if (cub->map[(int)(cub->player.x - cub->direction.x
		* (movespeed + 0.1))][(int)cub->player.y] != '1')
			cub->player.x -= cub->direction.x * movespeed;
		if (cub->map[(int)cub->player.x]
		[(int)(cub->player.y - cub->direction.y
		* (movespeed + 0.1))] != '1')
			cub->player.y -= cub->direction.y * movespeed;
	}
}

void	move_left_right(t_all *s, int direction)
{
	t_cub	*cub;
	float	movement_speed;

	cub = &s->cub;
	movement_speed = MOVE_SPEED + s->move.movement_speed;
	if (direction == 0)
	{
		if (cub->map[(int)(cub->player.x - cub->plane.x *
		(movement_speed + 0.1))][(int)cub->player.y] != '1')
			cub->player.x -= cub->plane.x * movement_speed;
		if (cub->map[(int)cub->player.x][(int)(cub->player.y
		- cub->plane.y * (movement_speed + 0.1))] != '1')
			cub->player.y -= cub->plane.y * movement_speed;
	}
	else
	{
		if (cub->map[(int)(cub->player.x + cub->plane.x *
		(movement_speed + 0.1))][(int)cub->player.y] != '1')
			cub->player.x += cub->plane.x * movement_speed;
		if (cub->map[(int)cub->player.x][(int)(cub->player.y
		+ cub->plane.y * (movement_speed + 0.1))] != '1')
			cub->player.y += cub->plane.y * movement_speed;
	}
}

void	turn_left_right(t_cub *cub, int direction)
{
	double	old_d_x;
	double	old_p_x;
	float	speed_rotation;

	old_d_x = cub->direction.x;
	old_p_x = cub->plane.x;
	speed_rotation = ROTATE_SPEED;
	if (direction == 0)
	{
		rot_sx(cub, old_d_x, old_p_x, speed_rotation);
	}
	else
	{
		cub->direction.x = cub->direction.x * cos(-speed_rotation)
		- cub->direction.y * sin(-speed_rotation);
		cub->direction.y = old_d_x * sin(-speed_rotation)
		+ cub->direction.y * cos(-speed_rotation);
		cub->plane.x = cub->plane.x * cos(-speed_rotation)
		- cub->plane.y * sin(-speed_rotation);
		cub->plane.y = old_p_x * sin(-speed_rotation)
		+ cub->plane.y * cos(-speed_rotation);
	}
}

void	rot_sx(t_cub *cub, double o_d_x, double o_p_x, float sp_rot)
{
	cub->direction.x = cub->direction.x * cos(sp_rot)
	- cub->direction.y * sin(sp_rot);
	cub->direction.y = o_d_x * sin(sp_rot)
			+ cub->direction.y * cos(sp_rot);
	cub->plane.x = cub->plane.x * cos(sp_rot)
			- cub->plane.y * sin(sp_rot);
	cub->plane.y = o_p_x * sin(sp_rot)
			+ cub->plane.y * cos(sp_rot);
}
