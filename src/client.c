#include "minitalk.h"

void cheak_input(int n)
{

    if(ac != 3)
    {
        ft_putstr("Error:[ ./client <pid> <message> ]\n");
        exit(1);
    }
    if(av[i] < 0)
    {
        ft_putstr("Error: invalid <PID>",1);
        exit(1);
    }
    if(!cheak_digit(av[1]))
    {
        ft_putstr("Eroor\n av < -1");
        exit(1);
    }
}

int main(int ac ,char **av)
{
    int 
    cheak_input(ac , av);
}
