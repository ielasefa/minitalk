/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:30:54 by iel-asef          #+#    #+#             */
/*   Updated: 2025/03/18 16:30:56 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	is_not_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (1);
		i++;
	}
	return (0);
}

void	cheak_input(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_putstr("Error:[./client <pid> <message> ]\n");
		exit(1);
	}
	pid = ft_atoi(av[1], NULL);
	if (pid <= 0)
	{
		ft_putstr("Error:invalid <PID>\n");
		exit(1);
	}
	if (is_not_digit(av[1]))
	{
		ft_putstr("Error:invalid11 <PID>\n");
		exit(1);
	}
}

void	send_msg(char s, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((s >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

void	handle_sig(int signum)
{
	if (signum == SIGUSR1)
		ft_putstr("Message successfully received✅\n");
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;
	char	*str;

	i = 0;
	cheak_input(ac, av);
	pid = ft_atoi(av[1], NULL);
	signal(SIGUSR1, handle_sig);
	str = av[2];
	while (str[i])
	{
		send_msg(str[i], pid);
		i++;
	}
	send_msg('\0', pid);
	return (0);
}
