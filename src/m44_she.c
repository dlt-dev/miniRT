/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_she.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 09:19:37 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/28 12:09:06 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformations.h"

static double	she_det(const t_m44 *m1)
{
	return (
		1
		+ (*m1)[1] * (*m1)[6] * (*m1)[8]
		+ (*m1)[2] * (*m1)[4] * (*m1)[9]
		- (*m1)[1] * (*m1)[4]
		- (*m1)[2] * (*m1)[8]
		- (*m1)[6] * (*m1)[9]
	);
}

int	m44_she(t_spara p, t_m44 *res)
{
	const t_m44	tmp = {
		1.0, p.xy, p.xz, 0.0,
		p.yx, 1.0, p.yz, 0.0,
		p.zx, p.zy, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0};

	if (!res || she_det(&tmp) == 0)
		return (-1);
	ft_memcpy(*res, tmp, sizeof(t_m44));
	return (0);
}
