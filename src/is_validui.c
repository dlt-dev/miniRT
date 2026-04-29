/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_validui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:14:44 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/29 14:14:53 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	is_validui(const char *str)
{
	unsigned long	result;
	int				i;

	if (!str || *str == '\0')
		return (false);
	i = 0;
	if (str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (false);
	result = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		result = result * 10 + (str[i] - '0');
		if (result > UINT_MAX)
			return (false);
		i++;
	}
	return (true);
}
