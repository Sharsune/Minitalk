/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:04:38 by sharsune          #+#    #+#             */
/*   Updated: 2023/03/29 15:04:40 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "libft/libft.h"
# include <signal.h>

typedef struct s_vars
{
	int	bit;
	int	len;
	int	c;
	int	len_known;
	int	byte_count;
	int	check;
}	t_vars;
#endif