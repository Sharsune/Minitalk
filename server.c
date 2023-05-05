/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:17:14 by sharsune          #+#    #+#             */
/*   Updated: 2023/04/06 13:17:16 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

static int	init_vars(t_vars *vars)
{
	vars->bit = 0;
	vars->len = 0;
	vars->c = 0;
	vars->len_known = 0;
	vars->byte_count = 0;
	return (1);
}

static void	make_string()
{



}

static void	signal_handler(int signal)
{
	t_vars		vars;
	static int	check;

	check = 0;
	if (check == 0)
		check += init_vars(&vars);
	if (signal == SIGUSR2 && vars.bit < 32 && vars.len_known == 0)
		vars.len |= (1 << vars.bit);
	if (signal == SIGUSR2 && vars.len_known == 1)
		vars.c |= (1 << vars.bit);
	vars.bit++;
	if (vars.bit == 32)
	{
		vars.bit == 0;
		vars.len_known == 1;
	}
	if (vars.bit == 8 && vars.len_known == 1)
	{
		

	}

}

int	main(void)
{
	ft_printf("Server pid is:%d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
}
