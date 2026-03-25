/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:43:46 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/24 08:27:37 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	rd_int(const t_ray *ray, const t_vect3 *disc_o, const t_vect3 *disc_n, double radius, double *t)
{
	t_vect3	pln_norm = vect3_unit(*disc_n);
	t_pln	disc_plane = (t_pln) {*disc_o, pln_norm, (t_color) {0,0,0,0}};
	//t_hitinfo	nothing;
	//t_itv		inter = (t_itv){0, INFINITY};
	
	//bool plane = pln_hit(&disc_plane, (t_ray *)ray, &nothing, &inter);
	
	
	bool	plane = ray_pln_intersection(ray, &disc_plane, t);
	if (!plane)
		return (false);
	t_vect3 Hp = ray_at(*ray,*t);
	t_vect3 Dd = vect3_sub(Hp, *disc_o);
	if (vect3_dot(Dd, Dd) > radius * radius)
		return (false);
	// *t = nothing.t;
	//printf("In my circle\n");
	return (true);
}
