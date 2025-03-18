/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:31:19 by iel-asef          #+#    #+#             */
/*   Updated: 2025/03/18 16:31:22 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_putnbr(int n)
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

static void	handler_sig(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	count = 0;
	static int	client_pid = 0;

	(void)context;
	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		count = 0;
		c = 0;
	}
	c = (c << 1) | (signum == SIGUSR1);
	count++;
	if (count == 8)
	{
		if (c == '\0')
		{
			ft_putchar('\n');
			kill(client_pid, SIGUSR1); 
		}
		else
			ft_putchar(c);
		count = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		ft_putstr("Error: This program does not accept arguments.\n");
		return (1);
	}
	ft_putstr("PID: ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	sa.sa_sigaction = handler_sig;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
