/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:35:56 by sharsune          #+#    #+#             */
/*   Updated: 2023/01/31 19:35:59 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	after_dot(const char *str, int i, int sign, int result)
{
	double	power;

	power = 1.0;
	while (ft_isdigit(str[i]))
	{
		result = 10.0 * result + (str[i] - '0');
		power *= 10.0;
		i++;
	}
	return (sign * result / power);
}

double	ft_atof(const char *str)
{
	double	result;
	double	power;
	int		i;
	int		sign;

	result = 0.0;
	power = 1.0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = 10.0 * result + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	return (after_dot(str, i, sign, result));
}
