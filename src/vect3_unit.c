/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3_unit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:30:33 by cybourge          #+#    #+#             */
/*   Updated: 2026/02/03 14:34:52 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vect3	vect3_unit(t_vect3 v)
{
	double	len;

	len = vect3_norm(v);
	if (len == 0.0)
		return ((t_vect3){0.0, 0.0, 0.0});
	return (vect3_div_scalar(v, len));
}
