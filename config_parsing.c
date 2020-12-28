/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <scorsaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:35:23 by scorsaro          #+#    #+#             */
/*   Updated: 2020/10/01 19:56:21 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_dot_cub_file(t_cub *cub, char *file_to_parse)
{
	int		fd;
	char	*str;

	if ((fd = open(file_to_parse, O_RDONLY)) < 0)
		ft_error(ERROR_DOT_CUB);
	while (get_next_line(fd, &str) > 0)
	{
		if (cub->map[0][0] != '\0' && str[0] == '\0')
			break ;
		ft_select(str, cub);
		free(str);
	}
	ft_select(str, cub);
	free(str);
	get_player_position(cub->map, cub);
	get_sprite(cub->map, cub);
	close(fd);
}

void	ft_select(char *line, t_cub *cub)
{
	int		i;
	int		index;

	i = 0;
	index = 0;
	index = skip_spaces(line, index);
	if (line[index] == 'R' && line[index + 1] == ' ')
		get_size(line, cub);
	if (line[index] == 'N' && line[index + 1] == 'O' && line[index + 2] == ' ')
		cub->no = get_texture(line, cub, cub->no);
	if (line[index] == 'S' && line[index + 1] == 'O' && line[index + 2] == ' ')
		cub->so = get_texture(line, cub, cub->so);
	if (line[index] == 'W' && line[index + 1] == 'E' && line[index + 2] == ' ')
		cub->we = get_texture(line, cub, cub->we);
	if (line[index] == 'E' && line[index + 1] == 'A' && line[index + 2] == ' ')
		cub->ea = get_texture(line, cub, cub->ea);
	if (line[index] == 'S' && line[index + 1] == ' ')
		cub->sprite = get_texture(line, cub, cub->sprite);
	if (line[index] == 'F' && line[index + 1] == ' ')
		cub->f = get_color(line, 0);
	if (line[index] == 'C' && line[index + 1] == ' ')
		cub->c = get_color(line, 0);
	while (line[i++] == ' ')
		ft_isdigit(line[i]) ? get_map(line, cub) : 0;
	ft_isdigit(line[0]) ? get_map(line, cub) : 0;
}

void	get_size(char *line, t_cub *cub)
{
	int		i;
	int		max_size[2];

	i = skip_spaces(line, 0);
	i += 1;
	if (cub->win.height != 0 && cub->win.width != 0)
		ft_error(ERROR_MULTIPLE_RESOLUTIONS);
	if (verif_size(line, i))
		return ;
	while (!ft_isdigit(line[i]))
		i++;
	if (ft_isdigit(line[i]))
		process_res_digits(line, cub, i);
	if (LINUX)
		mlx_get_screen_size(cub->mlx, &max_size[1], &max_size[0]);
	else if (APPLE)
	{
		max_size[0] = MAX_HEIGHT;
		max_size[1] = MAX_WIDTH;
	}
	cub->win.height > max_size[0] - 45 ? cub->win.height = max_size[0] - 45 : 0;
	cub->win.width > max_size[1] ? cub->win.width = max_size[1] : 0;
	cub->win.height < 10 ? cub->win.height = MIN_HEIGHT : 0;
	cub->win.width < 10 ? cub->win.width = MIN_WIDTH : 0;
}

void	process_res_digits(char *line, t_cub *cub, int i)
{
	i = skip_spaces(line, i);
	cub->win.width == 0 ? cub->win.width = ft_atoi(&line[i]) : 0;
	while (ft_isdigit(line[i]))
		i++;
	i = skip_spaces(line, i);
	cub->win.height == 0 ? cub->win.height = ft_atoi(&line[i]) : 0;
	while (ft_isdigit(line[i]))
		i++;
	i = skip_spaces(line, i);
	if (ft_isdigit(line[i]))
		ft_error(ERROR_RES_MUL_VAL);
}

int		verif_size(char *str, int index)
{
	int	i;

	i = index;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}
