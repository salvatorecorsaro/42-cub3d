/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_screenshot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <scorsaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:31:44 by scorsaro          #+#    #+#             */
/*   Updated: 2020/09/24 11:31:45 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	prepare_to_save(int fd, t_all *m, int tmp, int file_size)
{
	char	header[54];

	ft_bzero(header, 54);
	header[0] = (unsigned char)'B';
	header[1] = (unsigned char)'M';
	header[2] = (unsigned char)file_size;
	header[3] = (unsigned char)(file_size >> 8);
	header[4] = (unsigned char)(file_size >> 16);
	header[5] = (unsigned char)(file_size >> 24);
	header[10] = (unsigned char)54;
	header[14] = (unsigned char)40;
	header[18] = (unsigned char)tmp;
	header[19] = (unsigned char)(tmp >> 8);
	header[20] = (unsigned char)(tmp >> 16);
	header[21] = (unsigned char)(tmp >> 24);
	tmp = -m->cub.win.height;
	header[22] = (unsigned char)tmp;
	header[23] = (unsigned char)(tmp >> 8);
	header[24] = (unsigned char)(tmp >> 16);
	header[25] = (unsigned char)(tmp >> 24);
	header[26] = (unsigned char)1;
	header[28] = (unsigned char)32;
	write(fd, header, 54);
}

void	write_image_to_file(int fd, t_all *m)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)m->img.addr;
	while (i < m->cub.win.height)
		write(fd, &tmp[i++ * (m->img.line_length * 4)], m->cub.win.width * 4);
}

void	take_screenshot(t_all *s)
{
	int	fd;
	int	tmp;
	int	file_size;

	if ((fd = open("screenshot.bmp", O_CREAT | O_RDWR, S_IRWXU)) < 0)
		quit(s);
	tmp = s->cub.win.width;
	file_size = 14 + 40 + (s->cub.win.width * s->cub.win.height) * 4;
	prepare_to_save(fd, s, tmp, file_size);
	write_image_to_file(fd, s);
	close(fd);
	quit(s);
}
