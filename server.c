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

static void	empty_str_print(t_vars *vars)
{
	ft_printf("\n");
	vars->check = 1;
}

static void	init_vars(t_vars *vars)
{
	vars->bit = 0;
	vars->len = 0;
	vars->c = 0;
	vars->len_known = 0;
	vars->byte_count = 0;
	vars->check = 0;
}

static int	make_string(t_vars *vars)
{
	static char	*str = NULL;

	if (!str)
		str = malloc(sizeof(char) * vars->len + 1);
	if (!str)
		return (-1);
	str[vars->len + 1] = '\0';
	if (vars->byte_count <= vars->len)
		str[vars->byte_count] = vars->c;
	if (vars->byte_count == vars->len - 1)
	{
		ft_printf("%s\n", str);
		free (str);
		str = NULL;
		vars->check = 1;
	}
	return (1);
}

static void	signal_handler(int signal)
{
	static t_vars		vars = {0, 0, 0, 0, 0, 0};

	if (vars.check == 1)
		init_vars(&vars);
	if (signal == SIGUSR2 && vars.bit < 32 && vars.len_known == 0)
		vars.len |= (1 << vars.bit);
	if (signal == SIGUSR2 && vars.len_known == 1)
		vars.c |= (1 << vars.bit);
	vars.bit++;
	if (vars.bit == 32)
	{
		vars.bit = 0;
		vars.len_known = 1;
		if (vars.len == 0)
			empty_str_print(&vars);
	}
	if (vars.bit == 8 && vars.len_known == 1)
	{
		if (!make_string(&vars))
			exit (1);
		vars.byte_count++;
		vars.bit = 0;
		vars.c = 0;
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
