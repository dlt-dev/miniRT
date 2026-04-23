/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_wld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:00:19 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 13:23:26 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
/*
int	main(void)
{
	t_wld	wld;
	t_ray	ray;
	t_itxv	itxv;
	t_itx	hit;
	t_clr	clr;

	// Initialise Parameters
	ray = (t_ray) {.o = pt_crt(0, 0, -5), .dir = v4_crt(0,0,1)};
	wld_ini_dflt(&wld);
	itxv = itxv_crt(1);
	
	printf("===== Test I =====\n");
	
	wld_itx(&wld, &ray, &itxv); // Compute Intersections
	hit = itxv_hit(&itxv);		// Take nearest one
	itx_cal(&hit, &ray);		// Complete Intersection data
	clr = wld_shd(&wld, &hit);	// Get the color at the Intersection.
	v4_prt((t_v4 *)&clr);
	itx_prt(&hit);
	itxv_prt(&itxv);
	wld_prt(&wld);
	itxv_clr(&itxv);

	printf("===== Test II =====\n");

	wld.lgts.v[0].pos = pt_crt(0, 0.25, 0);
	ray = (t_ray) {.o = pt_crt(0,0,0), .dir = v4_crt(0,0,1)};
	wld_itx(&wld, &ray, &itxv);
	hit = itxv_hit(&itxv);
	itx_cal(&hit, &ray);
	clr = wld_shd(&wld, &hit);
	v4_prt((t_v4 *)&clr);
	itx_prt(&hit);
	itxv_prt(&itxv);
	wld_prt(&wld);
	itxv_clr(&itxv);
	

	printf("===== Test III =====\n");

	wld_ini_dflt(&wld);
	wld.objs.v[0].mtrl.amb = 1.0;
	wld.objs.v[1].mtrl.amb = 1.0;
	wld.objs.v[1].mtrl.clr = clr_crt(0, 0.5, 0.5, 0.5);
	ray = (t_ray) {.o = pt_crt(0, 0, 0.75), .dir = v4_crt(0, 0, -1)};
	clr = wld_clr_at(&wld, &ray, &itxv);
	v4_prt((t_v4 *)&clr);
	v4_prt((t_v4 *)&(wld.objs.v[1].mtrl.clr));
	//wld_prt(&wld);

	itxv_dlt(&itxv);
	return (0);
}
*/