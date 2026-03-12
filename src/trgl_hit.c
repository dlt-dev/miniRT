/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgl_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:01:12 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/12 14:32:42 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	trgl_hit(t_trgl *triangle, t_ray *ray, t_hitinfo *info, t_itv *interval)
{
	(void) interval;
	t_vect3	edge1 = vect3_sub(triangle->b, triangle->a);
	t_vect3	edge2 = vect3_sub(triangle->c, triangle->a);
	t_vect3	normal = vect3_cross(edge1, edge2);
	if (vect3_dot(normal, ray->dir) > 0) // Removes backfaces, assuming CCW triangles.
		return (false);
		
	t_vect3	ray_cross_e2 = vect3_cross(ray->dir, edge2);
	double	det = vect3_dot(edge1, ray_cross_e2);
	if (det > -EPS && det < EPS)
		return (false);					// Ray is parallel to triangle.
		
	double	inv_det = 1.0 / det;
	t_vect3	s = vect3_sub(ray->o, triangle->a);
	double	u = inv_det * vect3_dot(s, ray_cross_e2);
	if (u < -EPS || u - 1 > EPS)
		return (false);					// Ray passes outside of edge2's bounds.

	t_vect3	s_cross_e1 = vect3_cross(s, edge1);
	double	v = inv_det * vect3_dot(ray->dir, s_cross_e1);
	if (v < -EPS || u + v - 1 > EPS)
		return (false);					// Ray passes outside of edge1's bounds.
		
	// Compute the intersection
	double	t = inv_det * vect3_dot(edge2, s_cross_e1);
	if (t > EPS)
	{
		info->t = t;
		info->p = ray_at(*ray, t);
		info->front_face = true;
		return (true);
	}
	else
		return (false); // line intersection but no ray intersection (intersection is behind the ray: t < 0).
}