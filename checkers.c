/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <scorsaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:35:44 by scorsaro          #+#    #+#             */
/*   Updated: 2020/10/01 19:46:45 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_param(int argc, char **argv)
{
	if (argc >= 2)
		if ((ft_memcmp(argv[1], "--help", 7) == 0)
		|| ft_memcmp(argv[1], "-height", 3) == 0)
			ft_error(ERROR_HELP);
	if (argc == 3)
		if ((ft_memcmp(argv[2], "--help", 7) == 0)
		|| ft_memcmp(argv[2], "-height", 3) == 0)
			ft_error(ERROR_HELP);
	if (argc > 1)
		if (ft_strnstr(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 5) == NULL)
			ft_error(ERROR_DOT_CUB);
	if (argc == 3)
		if (ft_memcmp(argv[2], "--save", 7) != 0)
			ft_error(ERROR_DOT_CUB);
}

void	ft_error(char *error_code)
{
	ft_putendl_fd(error_code, 2);
	exit(0);
}
