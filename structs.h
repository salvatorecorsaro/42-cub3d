/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <scorsaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:32:15 by scorsaro          #+#    #+#             */
/*   Updated: 2020/09/24 11:32:17 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_sprite
{
	int			x;
	int			y;
	double		distance;
}				t_sprite;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_move
{
	int			esc;
	int			foward;
	int			back;
	int			left;
	int			right;
	int			turn_left;
	int			turn_right;
	float		movement_speed;
}				t_move;

typedef struct	s_coord_dbl
{
	double		x;
	double		y;
}				t_coord_dbl;

typedef struct	s_texture
{
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	struct
	{
		int		w;
		int		h;
	}			size;
}				t_texture;

typedef struct	s_raycast
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
	t_texture	*current;
	double		*z_buff;
}				t_raycast;

typedef struct	s_spr_calc
{
	double		spr_x;
	double		spr_y;
	double		invert;
	double		transform_x;
	double		transform_y;
	int			spr_screen_x;
	int			spr_h;
	int			draw_start_y;
	int			draw_end_y;
	int			spr_w;
	int			draw_start_x;
	int			draw_end_x;
	int			strip;
	int			tex_x;
	int			tex_y;
	int			*color;
}				t_spr_calc;

typedef struct	s_cub
{
	void		*mlx;
	void		*m_win;
	struct
	{
		int		width;
		int		height;
	}			win;
	t_texture	*no;
	t_texture	*ea;
	t_texture	*so;
	t_texture	*we;
	t_texture	*sprite;
	char		**map;
	int			f;
	int			c;
	t_coord_dbl	player;
	t_coord_dbl	plane;
	t_coord_dbl	direction;
	int			number_of_sprites;
	int			save;
}				t_cub;

typedef struct	s_image
{
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct	s_all
{
	t_cub		cub;
	t_move		move;
	t_raycast	ray;
	t_sprite	*sprite;
	t_image		img;
	t_spr_calc	spr_calc;
}				t_all;

#endif
