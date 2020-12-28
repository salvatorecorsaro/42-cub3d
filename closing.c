/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <scorsaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:35:37 by scorsaro          #+#    #+#             */
/*   Updated: 2020/10/01 19:48:08 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		quit(t_all *s)
{
	if (!s->cub.save)
	{
		mlx_destroy_window(s->cub.mlx, s->cub.m_win);
	}
	destroy_textures(s);
	ft_free_matrice(s->cub.map);
	free(s->ray.z_buff);
	free(s->sprite);
	exit(0);
}

void	destroy_textures(t_all *s)
{
	mlx_destroy_image(s->cub.mlx, s->cub.no->img);
	mlx_destroy_image(s->cub.mlx, s->cub.ea->img);
	mlx_destroy_image(s->cub.mlx, s->cub.so->img);
	mlx_destroy_image(s->cub.mlx, s->cub.we->img);
	mlx_destroy_image(s->cub.mlx, s->cub.sprite->img);
}
