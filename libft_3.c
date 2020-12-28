/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <scorsaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:30:25 by scorsaro          #+#    #+#             */
/*   Updated: 2020/10/01 20:03:14 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char		*dest;
	size_t		i;

	dest = b;
	i = -1;
	while (++i < len)
		dest[i] = c;
	return (b);
}

int		ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

void	ft_bzero(void *s, size_t n)
{
	char		*dest;
	size_t		i;

	dest = s;
	i = -1;
	while (++i < n)
		dest[i] = 0;
}
