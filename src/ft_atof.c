/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 07:57:42 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/30 12:06:22 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	parse_sign(const char **s, double *sign)
{
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			*sign = -1.0;
		(*s)++;
	}
}

static double	parse_integer(const char **s)
{
	double	result;

	result = 0.0;
	while (**s >= '0' && **s <= '9')
		result = result * 10.0 + (*(*s)++ - '0');
	return (result);
}

static double	parse_fraction(const char **s)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 10.0;
	if (**s == '.')
	{
		while (*++(*s) >= '0' && **s <= '9')
		{
			fraction += (**s - '0') / divisor;
			divisor *= 10.0;
		}
	}
	return (fraction);
}

double	ft_atof(const char *str)
{
	double	sign;
	double	result;

	sign = 1.0;
	result = 0.0;
	parse_sign(&str, &sign);
	result = parse_integer(&str);
	return (sign * (result + parse_fraction(&str)));
}
