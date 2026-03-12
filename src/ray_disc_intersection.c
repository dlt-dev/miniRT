/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_disc_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:43:46 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/12 11:43:55 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	ray_disc_intersection(t_ray *ray, t_vect3 *disc_o, t_vect3 *disc_n, double radius, double *t)
{
	t_pln	disc_plane = (t_pln) {*disc_o, *disc_n, (t_color) {0,0,0,0}};
	bool	plane = ray_pln_intersection(ray, &disc_plane, t);
	if (!plane)
		return (false);
	t_vect3 Hp = ray_at(*ray, *t);
	t_vect3 Dd = vect3_sub(Hp, *disc_o);
	if (vect3_dot(Dd, Dd) > radius * radius)
		return (false);
	return (true);
}
