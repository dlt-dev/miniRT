/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_hit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:32:09 by cybourge          #+#    #+#             */
/*   Updated: 2026/02/18 09:47:15 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	sphere_hit(t_sphere *sphere, t_ray *ray, t_hitinfo *info, t_itv *interval)
{
	const t_vect3	oc = vect3_sub(sphere->c, ray->o);
	double a = vect3_length_squared(ray->dir);
	double h = vect3_dot(ray->dir, oc);
	double c = vect3_length_squared(oc) - sphere->r * sphere->r;
	double discriminant = h * h - a * c;
	if (discriminant < 0.0)
		return (false);
	double root_discr = sqrt(discriminant);
	double root = (h - root_discr) / a;
	if (!itv_surrounds(interval, root))
	{
		root = (h + root_discr) / a;
		if (!itv_surrounds(interval, root))
			return (false);
	}
	info->t = root;
	info->p = ray_at(*ray, root);
	info->n = vect3_div_scalar(vect3_sub(info->p, sphere->c), sphere->r);
	hitinfo_set_face_normal(info, ray, &(info->n));
	return (true);
}