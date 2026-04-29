/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_validf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:13:50 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/29 14:49:47 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// Returns wether the argument is a string that represents a valid float.
// A valid float is a series of numbers 
// and an optional decimal point in-between.
// .{numbers} and {number}. are also considered valid.
bool	is_validf(const char *str)
{
	int	i;
	int	dot_count;
	int	digit_count;

	if (!str || *str == '\0')
		return (false);
	i = 0;
	dot_count = 0;
	digit_count = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (false);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			digit_count++;
		else if (str[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (false);
		}
		else
			return (false);
		i++;
	}
	return (digit_count > 0);
}
