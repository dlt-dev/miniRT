/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_validf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:13:50 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/30 12:05:41 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static bool	scan_float(const char *s, int *digits, int *dots)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			(*digits)++;
		else if (s[i] == '.')
		{
			(*dots)++;
			if (*dots > 1)
				return (false);
		}
		else
			return (false);
		i++;
	}
	return (true);
}

// Returns wether the argument is a string that represents a valid float.
// A valid float is a series of numbers 
// and an optional decimal point in-between.
// .{numbers} and {number}. are also considered valid.
bool	is_validf(const char *str)
{
	int	i;
	int	digits;
	int	dots;

	if (!str || !*str)
		return (false);
	i = 0;
	digits = 0;
	dots = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!scan_float(str + i, &digits, &dots))
		return (false);
	return (digits > 0);
}
