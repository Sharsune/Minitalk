/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:17:06 by sharsune          #+#    #+#             */
/*   Updated: 2023/04/06 13:17:07 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	str_to_bits(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & (1 << i)) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(400);
	}
}

static void	len_to_bits(int pid, int len)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if ((len & (1 << i)) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(400);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str_to_send;

	if (argc < 3)
		return (0);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		exit (1);
	str_to_send = argv[2];
	len_to_bits(pid, ft_strlen(str_to_send));
	while (*str_to_send != '\0')
		str_to_bits(pid, *str_to_send++);
	return (0);
}
