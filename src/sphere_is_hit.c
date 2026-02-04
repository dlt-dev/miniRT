/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_is_hit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:49:48 by cybourge          #+#    #+#             */
/*   Updated: 2026/02/04 14:13:55 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ray.h"

double	sphere_is_hit(t_sphere *sphere, t_ray *ray)
{
	const t_vect3	oc = vect3_sub(sphere->c, ray->o);
	double a = vect3_length_squared(ray->dir);
	double h = vect3_dot(ray->dir, oc);
	double c = vect3_length_squared(oc) - sphere->r * sphere->r;
	double discriminant = h * h - a * c;
	if (discriminant < 0.0)
		return (-1.0);
	else
		return ((h - sqrt(discriminant)) / a);
}
