/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_v3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:17:10 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/29 14:17:19 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Parses a triplet of numbers stored in str.
// writes the results in v as a vector if is_vector is true.
// writes the results in v as a point if is_vector is false.
// Returns -1 on erros, 0 otherwise.
int	prs_v3(char *str, t_v4 *v, bool is_vector)
{
	char	**xyz;
	int		len;

	if (!str || !v)
		return (-1);
	xyz = ft_split(str, ',');
	len = tab_len(xyz);
	if (len != 3)
	{
		tab_dlt(xyz);
		return (-1);
	}
	if (!is_validf(xyz[0]) || !is_validf(xyz[1]) || !is_validf(xyz[2]))
	{
		tab_dlt(xyz);
		return (-1);
	}
	if (is_vector)
		*v = v4_crt(ft_atof(xyz[0]), ft_atof(xyz[1]), ft_atof(xyz[2]));
	else
		*v = pt_crt(ft_atof(xyz[0]), ft_atof(xyz[1]), ft_atof(xyz[2]));
	tab_dlt(xyz);
	return (0);
}
