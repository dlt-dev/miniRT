/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_dflt_objs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:22:42 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/02 13:36:17 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Utility Function that sets up the Floor, Left Wall and Right Wall.
// Sphere 1 setup : The Floor
// Sphere 2 Setup : Left Wall
// Sphere 3 Setup : Right Wall
static void	setup_bg(t_wld *world)
{
	t_trf	trf;

	trf_ini(&trf);
	world->objs.v[0] = pln_crt();
	obj_trf(&(world->objs.v[0]), &trf);
	world->objs.v[0].mtrl.clr = clr_unpack(WHITE);
	world->objs.v[0].mtrl.spc = 0.1;
	world->objs.v[1] = pln_crt();
	trf_ini(&trf);
	trf_rot(&trf, PI / 2.0, -PI / 4.0, 0.0);
	trf_trl(&trf, 0, 0, 5);
	trf_trf(&trf);
	obj_trf(&(world->objs.v[1]), &trf);
	world->objs.v[1].mtrl.clr = clr_unpack(BLUE);
	world->objs.v[1].mtrl.spc = 0.1;
	world->objs.v[2] = pln_crt();
	trf_ini(&trf);
	trf_rot(&trf, PI / 2.0, PI / 4.0, PI / 6.0);
	trf_trl(&trf, 0, 0, 5);
	trf_trf(&trf);
	obj_trf(&(world->objs.v[2]), &trf);
	world->objs.v[2].mtrl.clr = clr_unpack(RED);
	world->objs.v[2].mtrl.spc = 0.1;
	trf_ini(&trf);
	trf_trl(&trf, EPS, EPS, EPS);
	trf_trf(&trf);
	pat_trf(&(world->objs.v[2].mtrl.pat), &trf);
	world->objs.v[2].mtrl.pat.pat = pat_chkr1;
}

// Utility function that sets up the left Sphere.
static void	setup_ele2(t_wld *world, size_t offset)
{
	t_trf	trf;

	world->objs.v[offset + 2] = sph_crt();
	trf_ini(&trf);
	trf_trl(&trf, -1.5, 0.33, -0.75);
	trf_scl(&trf, 0.33, 0.33, 0.33);
	trf_trf(&trf);
	obj_trf(&(world->objs.v[offset + 2]), &trf);
	world->objs.v[offset + 2].mtrl.clr = clr_unpack(0x00db3012);
	world->objs.v[offset + 2].mtrl.dif = 0.9;
	world->objs.v[offset + 2].mtrl.spc = 0.9;
	world->objs.v[offset + 2].mtrl.shi = 1000000;
	trf_ini(&trf);
	trf_scl(&trf, 0.1, 0.1, 0.1);
	trf_trf(&trf);
	pat_trf(&(world->objs.v[offset + 2].mtrl.pat), &trf);
	world->objs.v[offset + 2].mtrl.pat.pat = pat_strp1;
}

// Utility function that sets up the Middle and Right Spheres.
// Sphere 4 Setup : Middle Sphere
// Sphere 5 Setup : Right Sphere
static void	setup_ele1(t_wld *world, size_t offset)
{
	t_trf	trf;

	world->objs.v[offset + 0] = sph_crt();
	trf_ini(&trf);
	trf_trl(&trf, -0.5, 1.0, 0.5);
	trf_trf(&trf);
	obj_trf(&(world->objs.v[offset + 0]), &trf);
	world->objs.v[offset + 0].mtrl.clr = clr_unpack(0x00db1230);
	world->objs.v[offset + 0].mtrl.dif = 0.7;
	world->objs.v[offset + 0].mtrl.spc = 0.3;
	world->objs.v[offset + 0].mtrl.shi = 10;
	trf_ini(&trf);
	trf_rot(&trf, PI / 2.0, 0.0, 0.0);
	trf_scl(&trf, 0.5, 0.5, 0.5);
	trf_trf(&trf);
	pat_trf(&(world->objs.v[offset + 0].mtrl.pat), &trf);
	world->objs.v[offset + 0].mtrl.pat.pat = pat_chkr1;
	world->objs.v[offset + 1] = sph_crt();
	trf_ini(&trf);
	trf_scl(&trf, 0.5, 0.5, 0.5);
	trf_trl(&trf, 1.5, 0.5, -0.5);
	trf_trf(&trf);
	obj_trf(&(world->objs.v[offset + 1]), &trf);
	world->objs.v[offset + 1].mtrl.clr = clr_unpack(0x00db2834);
	world->objs.v[offset + 1].mtrl.dif = 0.5;
	world->objs.v[offset + 1].mtrl.spc = 0.9;
	trf_ini(&trf);
	trf_rot(&trf, PI / 2.0, 0.0, 0.0);
	trf_trf(&trf);
	pat_trf(&(world->objs.v[offset + 1].mtrl.pat), &trf);
	world->objs.v[offset + 1].mtrl.pat.pat = pat_lgrad1;
}

int	scn_dflt_objs(t_wld *world)
{
	world->objs = objv_crt(6);
	if (world->objs.cap == 0)
		return (-1);
	world->objs.len = 6;
	setup_bg(world);
	setup_ele1(world, 3);
	setup_ele2(world, 3);
	return (0);
}
