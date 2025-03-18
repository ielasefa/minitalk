/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:32:01 by iel-asef          #+#    #+#             */
/*   Updated: 2025/03/18 16:32:02 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

// util
int		ft_atoi(const char *str, int *j);
int		cheak_atoi(long r, int s, int *j);
int		ft_isdigit(int c);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
int		is_not_digit(char *s);
void	ft_putchar(char c);

void	send_msg(char s, int pid);

#endif
