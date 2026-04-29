/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 07:57:42 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/29 14:48:49 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double	ft_atof(const char *str)
{
	double	result;
	double	sign;
	double	fraction;
	double	divisor;

	result = 0.0;
	sign = 1.0;
	fraction = 0.0;
	divisor = 10.0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1.0;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10.0 + (*str++ - '0');
	if (*str == '.')
	{
		while (*++str >= '0' && *str <= '9')
		{
			fraction += (*str - '0') / divisor;
			divisor *= 10.0;
		}
	}
	return (sign * (result + fraction));
}
