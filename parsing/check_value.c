/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:58:34 by jdelattr          #+#    #+#             */
/*   Updated: 2026/02/27 12:22:42 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_vect(t_vect3 v)
{
	if (v.x < -1 || v.x > 1)
		return (0);
	if (v.y < -1 || v.y > 1)
		return (0);
	if (v.z < -1 || v.z > 1)
		return (0);
	if (v.x == 0 && v.y == 0 && v.z == 0)
		return (0);
	return (ERROR);
}

int	check_color(t_color c)
{
	if (c.r < 0 || c.r > 255)
		return (0);
	if (c.g < 0 || c.g > 255)
		return (0);
	if (c.b < 0 || c.b > 255)
		return (0);
	return (ERROR);
}

int	is_valid_number(const char *str)
{
	int	i;
	int	dot_count;

	if (!str || !*str)
		return (0);
	i = 0;
	dot_count = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (0);
		}
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_positive_int(const char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
