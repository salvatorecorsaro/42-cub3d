/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_initializer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <scorsaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:32:09 by scorsaro          #+#    #+#             */
/*   Updated: 2020/09/24 11:32:10 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_move(t_all *s)
{
	s->move.esc = 0;
	s->move.left = 0;
	s->move.turn_left = 0;
	s->move.right = 0;
	s->move.turn_right = 0;
	s->move.back = 0;
	s->move.foward = 0;
	s->move.movement_speed = 0;
}

void	init_cube(t_all *s)
{
	if ((s->cub.mlx = mlx_init()) == NULL)
		ft_error(ERROR_MLX_INIT);
	s->cub.save = FALSE;
	s->cub.win.width = 0;
	s->cub.win.height = 0;
	if ((s->cub.map = malloc(sizeof(s->cub.map))) == NULL)
		ft_error(ERROR_MALLOC);
	s->cub.map[0] = ft_strdup("");
	s->cub.player.x = -1;
	s->cub.player.y = -1;
	s->cub.direction.x = -1;
	s->cub.direction.y = 0;
	s->cub.plane.x = 0;
	s->cub.plane.y = 0.66;
	s->cub.no = NULL;
	s->cub.so = NULL;
	s->cub.ea = NULL;
	s->cub.we = NULL;
	s->cub.sprite = NULL;
	s->cub.f = -1;
	s->cub.c = -1;
}

void	init_sprite(t_all *s, int i)
{
	s->spr_calc.spr_x = s->sprite[i].x - s->cub.player.x + 0.5;
	s->spr_calc.spr_y = s->sprite[i].y - s->cub.player.y + 0.5;
	s->spr_calc.invert = 1 / (s->cub.plane.x
	* s->cub.direction.y - s->cub.direction.x * s->cub.plane.y);
	s->spr_calc.transform_x = s->spr_calc.invert * (s->cub.direction.y
	* s->spr_calc.spr_x - s->cub.direction.x * s->spr_calc.spr_y);
	s->spr_calc.transform_y = s->spr_calc.invert * (-s->cub.plane.y
	* s->spr_calc.spr_x + s->cub.plane.x * s->spr_calc.spr_y);
	s->spr_calc.spr_screen_x = (int)((s->cub.win.width / 2)
	* (1 + s->spr_calc.transform_x / s->spr_calc.transform_y));
	s->spr_calc.spr_h = abs((int)(s->cub.win.height / s->spr_calc.transform_y));
	s->spr_calc.draw_start_y = -s->spr_calc.spr_h / 2 + s->cub.win.height / 2;
	s->spr_calc.draw_start_y < 0 ? s->spr_calc.draw_start_y = 0 : 0;
	s->spr_calc.draw_end_y = s->spr_calc.spr_h / 2 + s->cub.win.height / 2;
	s->spr_calc.draw_end_y >= s->cub.win.height ?
			s->spr_calc.draw_end_y = s->cub.win.height - 1 : 0;
	s->spr_calc.spr_w = abs((int)(s->cub.win.height / s->spr_calc.transform_y));
	s->spr_calc.draw_start_x = -s->spr_calc.spr_w
	/ 2 + s->spr_calc.spr_screen_x;
	s->spr_calc.draw_start_x < 0 ? s->spr_calc.draw_start_x = 0 : 0;
	s->spr_calc.draw_end_x = s->spr_calc.spr_w / 2 + s->spr_calc.spr_screen_x;
	s->spr_calc.draw_end_x >= s->cub.win.width ?
			s->spr_calc.draw_end_x = s->cub.win.width - 1 : 0;
	s->spr_calc.strip = s->spr_calc.draw_start_x;
}
