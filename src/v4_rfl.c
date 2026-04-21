/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v4_rfl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:39:33 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/21 13:42:37 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector4.h"

// Returns the vector v = in - nrml * 2 * dot(in, nrml)
// in : incoming vector.
// nrml : normal vector around which the reflection takes place.
t_v4	v4_rfl(const t_v4 *in, const t_v4 *nrml)
{
	return (v4_sub(*in, v4_mul(*nrml, 2 * v4_dot(*in, *nrml))));
}