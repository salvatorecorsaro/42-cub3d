/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <scorsaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:31:37 by scorsaro          #+#    #+#             */
/*   Updated: 2020/09/24 11:31:39 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_raycast(t_all *s, int x)
{
	s->ray.camera_x = 2 * x / (double)s->cub.win.width - 1;
	s->ray.ray_dir_x = s->cub.direction.x + s->cub.plane.x * s->ray.camera_x;
	s->ray.ray_dir_y = s->cub.direction.y + s->cub.plane.y * s->ray.camera_x;
	s->ray.map_x = (int)s->cub.player.x;
	s->ray.map_y = (int)s->cub.player.y;
	s->ray.delta_dist_x = fabs(1 / s->ray.ray_dir_x);
	s->ray.delta_dist_y = fabs(1 / s->ray.ray_dir_y);
	s->ray.hit = 0;
}

void	dda(t_all *s)
{
	while (s->ray.hit == 0)
	{
		if (s->ray.side_dist_x < s->ray.side_dist_y)
		{
			s->ray.side_dist_x += s->ray.delta_dist_x;
			s->ray.map_x += s->ray.step_x;
			s->ray.side = 0;
		}
		else
		{
			s->ray.side_dist_y += s->ray.delta_dist_y;
			s->ray.map_y += s->ray.step_y;
			s->ray.side = 1;
		}
		if (s->cub.map[s->ray.map_x][s->ray.map_y] == '1')
			s->ray.hit = 1;
	}
	if (s->ray.side == 0)
		s->ray.perp_wall_dist =
		(s->ray.map_x - s->cub.player.x
		+ (1 - s->ray.step_x) / 2) / s->ray.ray_dir_x;
	else
		s->ray.perp_wall_dist = (s->ray.map_y - s->cub.player.y
		+ (1 - s->ray.step_y) / 2) / s->ray.ray_dir_y;
}

void	wall_size(t_all *s)
{
	s->ray.line_height = (int)(s->cub.win.height / s->ray.perp_wall_dist);
	s->ray.draw_start = -s->ray.line_height / 2 + s->cub.win.height / 2;
	if (s->ray.draw_start < 0)
		s->ray.draw_start = 0;
	s->ray.draw_end = s->ray.line_height / 2 + s->cub.win.height / 2;
	if (s->ray.draw_end >= s->cub.win.height)
		s->ray.draw_end = s->cub.win.height - 1;
}

int		raycast(t_all *s)
{
	int x;

	x = 0;
	while (x < s->cub.win.width)
	{
		init_raycast(s, x);
		calc_step_dist(s);
		dda(s);
		wall_size(s);
		write_img(s, s->ray.draw_start, s->ray.draw_end, x);
		s->ray.z_buff[x] = s->ray.perp_wall_dist;
		x++;
	}
	manage_sprite(s);
	return (0);
}
