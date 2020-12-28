/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <scorsaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:28:29 by scorsaro          #+#    #+#             */
/*   Updated: 2020/10/01 20:00:54 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_all	s;

	check_param(argc, argv);
	if (argc > 1 && argc <= 3)
	{
		init(&s, argv[1]);
		if (argc == 3)
			if (ft_memcmp(argv[2], "--save", 6) == 0)
			{
				s.cub.save = TRUE;
				game_loop(&s);
			}
		s.cub.m_win = mlx_new_window(
			s.cub.mlx, s.cub.win.width, s.cub.win.height, "cub3d");
		mlx_do_key_autorepeaton(s.cub.mlx);
		mlx_hook(s.cub.m_win, PRESS_EVENT, PRESS_MASK, ft_press, &s.move);
		mlx_hook(s.cub.m_win, RELEASE_EVENT, RELEASE_MASK, ft_release, &s.move);
		mlx_hook(s.cub.m_win, EXIT_EVENT, (1L << 17), &quit, &s);
		mlx_loop_hook(s.cub.mlx, &game_loop, &s);
		mlx_loop(s.cub.mlx);
	}
	ft_error(ERROR_WRONG_USAGE);
}

int		game_loop(t_all *s)
{
	s->img.img = mlx_new_image(s->cub.mlx, s->cub.win.width, s->cub.win.height);
	s->img.addr = (int *)mlx_get_data_addr(
		s->img.img, &s->img.bits_per_pixel,
		&s->img.line_length, &s->img.endian);
	s->img.line_length /= 4;
	raycast(s);
	s->cub.save ? take_screenshot(s) : 0;
	ft_move(s);
	mlx_put_image_to_window(s->cub.mlx, s->cub.m_win, s->img.img, 0, 0);
	mlx_destroy_image(s->cub.mlx, s->img.img);
	return (0);
}

void	init(t_all *s, char *arg)
{
	init_cube(s);
	init_move(s);
	parse_dot_cub_file(&s->cub, arg);
	check_parse_error(&s->cub);
	if ((s->ray.z_buff = malloc(
		sizeof(*s->ray.z_buff) * s->cub.win.width)) == NULL)
		ft_error(ERROR_MALLOC);
	if ((s->sprite = malloc(
		sizeof(*s->sprite) * s->cub.number_of_sprites)) == NULL)
		ft_error(ERROR_MALLOC);
	index_sprite(s);
}

void	check_parse_error(t_cub *cub)
{
	int	map_error;

	if (cub->win.width <= 0 || cub->win.height <= 0)
		ft_error(ERROR_RESOLUTION);
	if (!cub->no || !cub->so || !cub->ea || !cub->we)
		ft_error(ERROR_TEXTURES);
	if (!cub->no->img || !cub->ea->img || !cub->so->img || !cub->we->img)
		ft_error(ERROR_TEXTURES);
	if (!cub->sprite)
		ft_error(ERROR_SPRITE);
	if (!cub->sprite->img)
		ft_error(ERROR_SPRITE);
	if (cub->f == -1)
		ft_error(ERROR_FLOOR);
	if (cub->c == -1)
		ft_error(ERROR_CEILING);
	map_error = check_map(cub);
	if (map_error)
		ft_free_matrice(cub->map);
	if (map_error)
		ft_error(ERROR_MAP);
	if (cub->player.x == -1 || cub->player.y == -1)
		ft_error(ERROR_START_POSITION);
}
