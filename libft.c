/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <scorsaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:30:37 by scorsaro          #+#    #+#             */
/*   Updated: 2020/10/01 20:03:37 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	char	*stri1;
	char	*stri2;
	size_t	i;

	stri1 = (char *)str1;
	stri2 = (char *)str2;
	i = -1;
	if (stri1 == NULL && stri2 == NULL)
		return (0);
	while (++i < n)
		if (stri1[i] != stri2[i])
			return ((unsigned char)stri1[i] - (unsigned char)stri2[i]);
	return (0);
}

char	*ft_strnstr(const char *big, const char *needle, size_t len)
{
	size_t		i;
	size_t		a;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		a = 0;
		while (big[i + a] == needle[a] && i + a < len)
		{
			if (needle[a + 1] == '\0')
				return ((char *)&big[i]);
			a++;
		}
		i++;
	}
	return (0);
}

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	i = -1;
	if (s)
		while (s[++i])
			ft_putchar_fd(s[i], fd);
}
