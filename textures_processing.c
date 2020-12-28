/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_processing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <scorsaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:32:22 by scorsaro          #+#    #+#             */
/*   Updated: 2020/09/24 11:32:23 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*get_texture(char *line, t_cub *cub, t_texture *texture)
{
	int			i;
	int			j;
	t_texture	*img;
	char		pth[257];

	i = skip_spaces(line, 0) + 2;
	texture != NULL ? ft_error(ERROR_TOO_MANY_TEXTURES) : 0;
	j = check_textures(line, i);
	ft_memset(&pth, 0, 257);
	i = skip_spaces(line, i);
	while ((line[i] != 32 || line[i] != 9) && line[i])
		pth[j++] = line[i++];
	if ((img = malloc(sizeof(*img))) == NULL)
		ft_error(ERROR_MALLOC);
	img->img = mlx_xpm_file_to_image(cub->mlx, pth,
	&img->size.w, &img->size.h);
	img->addr = (int *)mlx_get_data_addr(img->img,
	&img->bits_per_pixel, &img->line_length, &img->endian);
	return (img);
}

int			check_textures(char *line, int index)
{
	int	i;
	int	j;
	int	fd;

	i = skip_spaces(line, index);
	j = i;
	while (line[j] && (line[j] != 32 || line[j] != 9))
		j++;
	if (line[j - 4] == '.')
	{
		line[j - 3] != 'x' ? ft_error(ERROR_DOT_XPM) : 0;
		line[j - 2] != 'p' ? ft_error(ERROR_DOT_XPM) : 0;
		line[j - 1] != 'm' ? ft_error(ERROR_DOT_XPM) : 0;
	}
	((fd = open(&line[i], O_RDONLY)) == -1) ? ft_error(ERROR_TEXTURE_OPEN) : 0;
	close(fd);
	return (0);
}

void		index_sprite(t_all *s)
{
	int	count;
	int i;
	int j;

	i = 0;
	count = 0;
	while (s->cub.map[i][0])
	{
		j = 0;
		while (s->cub.map[i][j])
		{
			if (s->cub.map[i][j] > '1')
			{
				s->sprite[count].x = i;
				s->sprite[count].y = j;
				count++;
			}
			j++;
		}
		i++;
	}
}

void		get_sprite(char **map, t_cub *cub)
{
	int i;
	int j;

	i = 0;
	cub->number_of_sprites = 0;
	while (map[i][0])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] > '1')
				cub->number_of_sprites++;
			j++;
		}
		i++;
	}
}
