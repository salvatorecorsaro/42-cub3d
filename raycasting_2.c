/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <scorsaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:31:27 by scorsaro          #+#    #+#             */
/*   Updated: 2020/09/24 11:31:31 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	write_img(t_all *s, int draw_start, int draw_end, int x)
{
	int i;

	i = 0;
	while (i < draw_start)
	{
		s->img.addr[i * s->img.line_length + x] = s->cub.c;
		i++;
	}
	i = textures_wall(s, i, x, draw_end);
	while (i < s->cub.win.height)
	{
		s->img.addr[i * s->img.line_length + x] = s->cub.f;
		i++;
	}
}

int		textures_wall(t_all *s, int i, int x, int draw_start)
{
	int	tex_y;
	int color;

	get_right_texture(s);
	calc_vars(s, i);
	while (i < draw_start)
	{
		tex_y = (int)s->ray.tex_pos & (s->ray.current->size.h - 1);
		s->ray.tex_pos += s->ray.step;
		if (s->ray.current->size.h < 64 && APPLE)
			color = s->ray.current->addr[tex_y * (s->ray.current->size.h
			* 64 / s->ray.current->size.h) + s->ray.tex_x];
		else
			color = s->ray.current->addr[tex_y * s->ray.current->size.h
			+ s->ray.tex_x];
		if ((color & 0x00FFFFFF) == 0)
			color = 0;
		s->img.addr[i * s->img.line_length + x] = color;
		i++;
	}
	return (i);
}

void	get_right_texture(t_all *s)
{
	if (s->ray.ray_dir_y >= 0 && s->ray.side == 1)
		s->ray.current = s->cub.we;
	else if (s->ray.ray_dir_y < 0 && s->ray.side == 1)
		s->ray.current = s->cub.ea;
	else if (s->ray.ray_dir_x >= 0 && s->ray.side == 0)
		s->ray.current = s->cub.no;
	else
		s->ray.current = s->cub.so;
}

void	calc_vars(t_all *s, int i)
{
	if (s->ray.side == 0)
		s->ray.wall_x = s->cub.player.y + s->ray.perp_wall_dist
		* s->ray.ray_dir_y;
	else
		s->ray.wall_x = s->cub.player.x + s->ray.perp_wall_dist
		* s->ray.ray_dir_x;
	s->ray.wall_x -= floor(s->ray.wall_x);
	s->ray.tex_x = (int)(s->ray.wall_x * (double)s->ray.current->size.h);
	if ((s->ray.side == 0 && s->ray.ray_dir_x > 0)
	|| (s->ray.side == 1 && s->ray.ray_dir_y < 0))
		s->ray.tex_x = s->ray.current->size.w - s->ray.tex_x - 1;
	s->ray.step = 1.0 * s->ray.current->size.h / s->ray.line_height;
	s->ray.tex_pos = (i - s->cub.win.height / 2 + s->ray.line_height / 2)
	* s->ray.step;
}

void	calc_step_dist(t_all *s)
{
	if (s->ray.ray_dir_x < 0)
	{
		s->ray.step_x = -1;
		s->ray.side_dist_x = (s->cub.player.x - s->ray.map_x)
		* s->ray.delta_dist_x;
	}
	else
	{
		s->ray.step_x = 1;
		s->ray.side_dist_x = (s->ray.map_x + 1.0 - s->cub.player.x)
		* s->ray.delta_dist_x;
	}
	if (s->ray.ray_dir_y < 0)
	{
		s->ray.step_y = -1;
		s->ray.side_dist_y = (s->cub.player.y - s->ray.map_y)
		* s->ray.delta_dist_y;
	}
	else
	{
		s->ray.step_y = 1;
		s->ray.side_dist_y = (s->ray.map_y + 1.0 - s->cub.player.y)
		* s->ray.delta_dist_y;
	}
}
