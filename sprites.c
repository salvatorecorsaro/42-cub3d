/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <scorsaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:31:51 by scorsaro          #+#    #+#             */
/*   Updated: 2020/09/24 11:31:56 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	manage_sprite(t_all *s)
{
	int		i;

	i = 0;
	while (i < s->cub.number_of_sprites)
	{
		s->sprite[i].distance = ((s->cub.player.x - s->sprite[i].x)
		* (s->cub.player.x - s->sprite[i].x)
		+ (s->cub.player.y - s->sprite[i].y)
		* (s->cub.player.y - s->sprite[i].y));
		i++;
	}
	sort_sprite(s);
	sprite_orientation(s);
}

void	sort_sprite(t_all *s)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < s->cub.number_of_sprites)
	{
		j = i + 1;
		while (j < s->cub.number_of_sprites)
		{
			if (s->sprite[i].distance < s->sprite[j].distance)
			{
				tmp = s->sprite[i];
				s->sprite[i] = s->sprite[j];
				s->sprite[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	sprite_orientation(t_all *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->cub.number_of_sprites)
	{
		init_sprite(s, i);
		while (s->spr_calc.strip < s->spr_calc.draw_end_x)
		{
			s->spr_calc.tex_x = (int)(256 * (s->spr_calc.strip
			- (-s->spr_calc.spr_w / 2 + s->spr_calc.spr_screen_x))
			* s->cub.sprite->size.w / s->spr_calc.spr_w) / 256;
			j = s->spr_calc.draw_start_y;
			if (s->spr_calc.transform_y > 0 && s->spr_calc.strip > 0
			&& s->spr_calc.strip < s->cub.win.width
			&& s->spr_calc.transform_y < s->ray.z_buff[s->spr_calc.strip])
				draw_sprite(s, j);
			s->spr_calc.strip++;
		}
		i++;
	}
}

void	draw_sprite(t_all *s, int j)
{
	int d;

	while (j < s->spr_calc.draw_end_y)
	{
		d = j * 256 - s->cub.win.height * 128 + s->spr_calc.spr_h * 128;
		s->spr_calc.tex_y = ((d * s->cub.sprite->size.h)
		/ s->spr_calc.spr_h) / 256;
		if (s->cub.sprite->size.h < 64 && APPLE)
			s->spr_calc.color = &s->cub.sprite->addr[
				s->cub.sprite->size.w * (s->spr_calc.tex_y * 64
				/ s->cub.sprite->size.h) + s->spr_calc.tex_x];
		else
			s->spr_calc.color = &s->cub.sprite->addr[
					s->cub.sprite->size.w * s->spr_calc.tex_y +
					s->spr_calc.tex_x];
		if ((*s->spr_calc.color & 0x00FFFFFF) != 0)
			s->img.addr[j * s->img.line_length
			+ s->spr_calc.strip] = *s->spr_calc.color;
		j++;
	}
}
