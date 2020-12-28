/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <scorsaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:30:57 by scorsaro          #+#    #+#             */
/*   Updated: 2020/09/24 11:30:59 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_map(char *line, t_cub *cub)
{
	int		i[2];
	char	**tmp;

	i[0] = -1;
	i[1] = 0;
	while (cub->map[i[1]][0] != '\0')
		i[1]++;
	if ((tmp = malloc(sizeof(*tmp) * (i[1] + 2))) == NULL)
		ft_error(ERROR_MALLOC);
	while (++i[0] < i[1])
		tmp[i[0]] = ft_strdup(cub->map[i[0]]);
	ft_free_matrice(cub->map);
	tmp[i[0]] == NULL ? free(tmp[i[0]]) : 0;
	tmp[i[0]++] = ft_strdup(line);
	tmp[i[0]] = ft_strdup("");
	cub->map = tmp;
}

void	ft_free_matrice(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i][0] != '\0')
		{
			free(map[i++]);
		}
		free(map[i]);
		free(map);
	}
}

int		find_char_in_str(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		if (str[i++] == c)
			return (TRUE);
	return (FALSE);
}

int		get_next_line(int fd, char **line)
{
	int			read_size;
	char		buf[4096];
	static char	*stock = NULL;

	if (line == NULL || fd < 0)
		return (-3);
	*line = NULL;
	read_size = 1;
	while (!(newline_check(stock, read_size)))
	{
		if ((read_size = read(fd, buf, 4095)) == -1)
			return (-3);
		buf[read_size] = '\0';
		if ((stock = buf_join(stock, buf)) == NULL)
			return (-3);
	}
	if ((*line = get_line(stock)) == NULL)
		return (-3);
	if (read_size == 0)
		free(stock);
	if (read_size == 0)
		return (0);
	if ((stock = stock_trim(stock)) == NULL)
		return (-3);
	return (1);
}
