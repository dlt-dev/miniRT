/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 08:54:50 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/17 09:57:26 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
int main(void)
{
	t_obj	cone = con_crt();
	t_ray	ray;
	t_itxv	itxv;

	itxv = itxv_crt(2);
	if (itxv.cap == 0)
		return (1);

	// Cone Intersections
	// ray = (t_ray){.o = pt_crt(0,0,-5), .dir = v4_uni(v4_crt(0,0,1))};
	// con_hit(&cone, &ray, &itxv);
	// ray = (t_ray){.o = pt_crt(0,0,-5), .dir = v4_uni(v4_crt(1,1,1))};
	// con_hit(&cone, &ray, &itxv);
	// ray = (t_ray){.o = pt_crt(1,1,-5), .dir = v4_uni(v4_crt(-0.5,-1,1))};
	// con_hit(&cone, &ray, &itxv);
	// ray = (t_ray){.o = pt_crt(0,0,-1), .dir = v4_uni(v4_crt(0,1,1))};
	// con_hit(&cone, &ray, &itxv);

	// End Caps Intersection
	// ray = (t_ray){.o = pt_crt(0,0,-5), .dir = v4_uni(v4_crt(0,1,0))};
	// con_hit(&cone, &ray, &itxv);
	// printf("|%ld|", itxv.len);
	// itxv.len = 0;
	// ray = (t_ray){.o = pt_crt(0,0,-0.25), .dir = v4_uni(v4_crt(0,1,1))};
	// con_hit(&cone, &ray, &itxv);
	// printf("|%ld|", itxv.len);
	// itxv.len = 0;
	// ray = (t_ray){.o = pt_crt(0,0,-0.25), .dir = v4_uni(v4_crt(0,1,0))};
	// con_hit(&cone, &ray, &itxv);
	// printf("|%ld|", itxv.len);
	// itxv.len = 0;
	// itxv_prt(&itxv);
	// itxv_dlt(&itxv);

	// Normal Vector Tests :
	t_v4	normal;
	t_pt	point;

	point = pt_crt(0,0,0);
	con_nrml(&cone, &point, &normal);
	v4_prt(&normal);
	point = pt_crt(1,1,1);
	con_nrml(&cone, &point, &normal);
	v4_prt(&normal);
	point = pt_crt(-1,-1,0);
	con_nrml(&cone, &point, &normal);
	v4_prt(&normal);

	return (0);
}
*/