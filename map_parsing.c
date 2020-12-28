/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <scorsaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:31:06 by scorsaro          #+#    #+#             */
/*   Updated: 2020/09/24 11:32:02 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_map(t_cub *cub)
{
	int		i;
	int		j;
	char	**map;

	map = cub->map;
	i = 0;
	while (map[i][0] != '\0')
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (find_char_in_str(VALID_SIGN, map[i][j]))
			{
				if (i == 0 || map[i + 1][0] == 0
				|| j == 0 || map[i][j + 1] == 0)
					return (1);
				if (check_square(map, i, j))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		check_square(char **row, int i, int j)
{
	if (!ft_ismap(row[i - 1][j - 1]) || !ft_ismap(row[i - 1][j])
	|| !ft_ismap(row[i - 1][j + 1]) || !ft_ismap(row[i][j + 1])
	|| !ft_ismap(row[i + 1][j + 1]) || !ft_ismap(row[i + 1][j])
	|| !ft_ismap(row[i + 1][j - 1]) || !ft_ismap(row[i][j - 1]))
		return (TRUE);
	return (FALSE);
}

int		ft_ismap(char x)
{
	if (x == 'N' || x == 'E' || x == 'S' || x == 'W'
	|| x == '1' || x == '0' || x == '2')
		return (TRUE);
	return (FALSE);
}

void	get_player_position(char **map, t_cub *cub)
{
	int x;
	int y;

	x = 0;
	while (map[x][0] != 0)
	{
		y = 0;
		while (map[x][y])
		{
			if (ft_isalpha(map[x][y]) && cub->player.x
			!= -1 && cub->player.y != -1)
				ft_error(ERROR_MAP);
			if ((map[x][y] == 'N' || map[x][y] == 'E' || map[x][y] == 'S'
			|| map[x][y] == 'W')
			&& cub->player.x == -1 && cub->player.y == -1)
			{
				cub->player.x = x + 0.5;
				cub->player.y = y + 0.5;
				get_player_direction(cub, map[x][y]);
				cub->map[x][y] = '0';
			}
			y++;
		}
		x++;
	}
}

void	get_player_direction(t_cub *cub, char c)
{
	cub->direction.x = 0;
	cub->direction.y = 0;
	cub->plane.x = 0;
	cub->plane.y = 0;
	if (c == 'N')
	{
		cub->direction.x = -1;
		cub->plane.y = 0.66;
	}
	else if (c == 'S')
	{
		cub->direction.x = 1;
		cub->plane.y = -0.66;
	}
	else if (c == 'W')
	{
		cub->direction.y = -1;
		cub->plane.x = -0.66;
	}
	else if (c == 'E')
	{
		cub->direction.y = 1;
		cub->plane.x = 0.66;
	}
}
