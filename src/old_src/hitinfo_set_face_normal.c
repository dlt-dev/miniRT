/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitinfo_set_face_normal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 09:25:14 by cybourge          #+#    #+#             */
/*   Updated: 2026/02/18 09:38:50 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	hitinfo_set_face_normal(t_hitinfo *hitinfo, const t_ray *ray, const t_vect3 *outward_normal)
{
	if (!double_equal(vect3_norm(*outward_normal), 1.0))
		fprintf(stderr, "WARNING NON UNIT VECTOR DETECTED IN set_face_normal()\n");
	hitinfo->front_face = vect3_dot(ray->dir, *outward_normal) < 0;
	if (hitinfo->front_face)
		hitinfo->n = *outward_normal;
	else
		hitinfo->n = vect3_inv(*outward_normal);
}