/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:31:33 by iel-asef          #+#    #+#             */
/*   Updated: 2025/03/18 16:31:35 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	cheak_atoi(long r, int s, int *j)
{
	if ((r * s) > 2147483647 || (r * s) < -2147483648)
	{
		if (j != NULL)
			*j = 1;
		return (0);
	}
	return (1);
}

int	ft_atoi(const char *str, int *j)
{
	long	r;
	int		i;
	int		s;

	i = 0;
	s = 1;
	r = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		if (cheak_atoi(r, s, j) == 0)
			return (0);
		i++;
	}
	return (r * s);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
}
