#include "minitalk.h"

void ft_putchar (char c)
{
	write(1 , &c , 1);
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

int	cheak_digit(char *s)
{
	int i = 0;
	while(s[i])
	{
		if(ft_isdigit(s[i]));
			return 0;
		i++;
	}
	return 1;
}

void ft_putstr(char *s)
{
	int  i = 0;
	while(s[i])
	{
		write(2 , &s[i] , 1);
		i++;
	}
}

void	ft_putnbr_fd(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	else
		ft_putchar(nb + '0');
}
