/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <scorsaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:35:16 by scorsaro          #+#    #+#             */
/*   Updated: 2020/10/01 19:49:12 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color(char *line, int index)
{
	int		i;
	t_color	rgb;

	i = index + 1;
	i = skip_spaces(line, i);
	rgb.r = ft_atoi(&line[i]);
	while (line[i] != ',' && line[i])
		i++;
	i++;
	i = skip_spaces(line, i);
	rgb.g = ft_atoi(&line[i]);
	while (line[i] != ',' && line[i])
		i++;
	i = skip_spaces(line, ++i);
	rgb.b = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i = skip_spaces(line, i);
	if (ft_isdigit(line[i]) || line[i] == ',')
		ft_error(ERROR_COLORS);
	if (rgb.r < 0 || rgb.g < 0 || rgb.b < 0 || rgb.r > 255 || rgb.g > 255 ||
		rgb.b > 255)
		return (-1);
	return ((rgb.r * 256 * 256) + (rgb.g * 256) + (rgb.b));
}

int	skip_spaces(char *line, int index)
{
	int		len;

	len = ft_strlen(line);
	while (index < len && (line[index] == 32 || line[index] == 9))
	{
		index++;
	}
	return (index);
}
