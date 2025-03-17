#include "minitalk.h"


int main(int ac ,char **av)
{
	(void)argv;
	if (ac != 1)
	{
		ft_putstr("Error: This program does not accept arguments.\n");
		return (1);
	}
    ft_putstr("PID:\n");
	ft_putnbr(getpid());
	ft_putstr("\n");
}