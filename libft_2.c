/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <scorsaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:30:17 by scorsaro          #+#    #+#             */
/*   Updated: 2020/10/01 20:02:55 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int lnb;

	lnb = n;
	if (lnb < 0)
	{
		ft_putchar_fd('-', fd);
		lnb = -lnb;
	}
	if (lnb > 9)
		ft_putnbr_fd(lnb / 10, fd);
	ft_putchar_fd(lnb % 10 + '0', fd);
}

char	*ft_strdup(const char *src)
{
	int			s;
	int			i;
	char		*stored;

	s = 0;
	i = 0;
	while (src[s] != '\0')
		s++;
	if (!(stored = (char *)malloc((s + 1) * (sizeof(char)))))
		return (0);
	while (src[i] != '\0')
	{
		stored[i] = src[i];
		i++;
	}
	stored[i] = '\0';
	return (stored);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		ft_atoi(char const *str)
{
	int		is_negative;
	int		value;
	int		max_count;

	is_negative = 0;
	value = 0;
	max_count = 0;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_negative = 1;
		str++;
	}
	while ((*str <= '9') && (*str >= '0'))
	{
		value = (value * 10) - (*str - '0');
		str++;
		max_count++;
	}
	if (max_count >= 19)
		return (is_negative ? 0 : -1);
	return (is_negative ? value : -value);
}
