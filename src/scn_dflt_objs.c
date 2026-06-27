/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_dflt_objs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:22:42 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/27 17:57:04 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	setup_spheres(t_wld *world, t_scn *scene, size_t offset)
{
	t_trf	trf;

	// Sphere 1 : Texture + BUMP
	world->objs.v[offset] = sph_crt();
	trf_ini(&trf);
	trf_trl(&trf, 20, 0, 10);
	trf_scl(&trf, 2, 2, 2);
	trf_trf(&trf);
	obj_trf(&(world->objs.v[offset]), &trf);
	trf_ini(&trf);
	trf_trf(&trf);
	mtl_trf(&(world->objs.v[offset].mtrl), &trf);
	world->objs.v[offset].mtrl.tex = &(scene->texv.v[4]);
	world->objs.v[offset].mtrl.hmap = &(scene->hmapv.v[0]);
	world->objs.v[offset].gcord = sph_cord;
	offset++;

	// Sphere 2 : Checkers + Scale
	world->objs.v[offset] = sph_crt();
	trf_ini(&trf);
	trf_trl(&trf, 15, 0, 10);
	trf_scl(&trf, 2, 2, 2);
	trf_trf(&trf);
	obj_trf(&(world->objs.v[offset]), &trf);
	trf_ini(&trf);
	trf_scl(&trf, 0.1, 0.1, 0.1);
	trf_trf(&trf);
	mtl_trf(&(world->objs.v[offset].mtrl), &trf);
	world->objs.v[offset].mtrl.tex = &(scene->texv.v[2]);
	world->objs.v[offset].gcord = sph_cord2;
	offset++;

	//Sphere 3 : Striped
	world->objs.v[offset] = sph_crt();
	trf_ini(&trf);
	trf_trl(&trf, 10, 0, 10);
	trf_scl(&trf, 2, 2, 2);
	trf_trf(&trf);
	obj_trf(&(world->objs.v[offset]), &trf);
	trf_ini(&trf);
	trf_scl(&trf, 0.07, 0.07, 0.07);
	trf_trf(&trf);
	mtl_trf(&(world->objs.v[offset].mtrl), &trf);
	world->objs.v[offset].mtrl.tex = &(scene->texv.v[0]);
	world->objs.v[offset].gcord = sph_cord;
	offset++;

	// Sphere 4 : BUMP only
	world->objs.v[offset] = sph_crt();
	world->objs.v[offset].mtrl.clr = clr_unpack(WHITE);
	trf_ini(&trf);
	trf_trl(&trf, 5, 0, 10);
	trf_scl(&trf, 2, 2, 2);
	trf_trf(&trf);
	obj_trf(&(world->objs.v[offset]), &trf);
	trf_ini(&trf);
	trf_rot(&trf, PI/2, 0,0);
	trf_trf(&trf);
	mtl_trf(&(world->objs.v[offset].mtrl), &trf);
	world->objs.v[offset].mtrl.hmap = &(scene->hmapv.v[0]);
	world->objs.v[offset].gcord = sph_cord;
	offset++;
}

static void	setup_planes(t_wld *world, t_scn *scene, size_t offset)
{
	t_trf	trf;
	
	// Left Plane : Checkers
	scene->world.objs.v[offset] = pln_crt();
	trf_ini(&trf);
	trf_rot(&trf, 0, 0, PI / 2.0);
	trf_scl(&trf, 3, 3, 3);
	trf_trl(&trf, -10, 0, 0);
	trf_trf(&trf);
	obj_trf(&(scene->world.objs.v[offset]), &trf);
	trf_ini(&trf);
	trf_trf(&trf);
	mtl_trf(&(world->objs.v[offset].mtrl), &trf);
	world->objs.v[offset].mtrl.tex = &(scene->texv.v[2]);
	world->objs.v[offset].gcord = pln_cord;
	offset++;

	// Floor : Mirror
	scene->world.objs.v[offset] = pln_crt();
	trf_ini(&trf);
	trf_rot(&trf, 0, 0, 0);
	trf_trl(&trf, 0, -5, 0);
	scene->world.objs.v[offset].mtrl.rfl = 1.0;
	scene->world.objs.v[offset].mtrl.dif = 0.5;
	scene->world.objs.v[offset].mtrl.amb = 0.0;
	trf_trf(&trf);
	obj_trf(&(scene->world.objs.v[offset]), &trf);
	offset++;
}

int	scn_dflt_objs(t_wld *world, t_scn *scene)
{
	const size_t	obj_nb = 6;

	world->objs = objv_crt(obj_nb);
	if (world->objs.cap == 0)
		return (-1);
	world->objs.len = obj_nb;
	setup_spheres(world, scene, 0);
	setup_planes(world, scene, 4);
	return (0);
}
/*
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
	world->objs.v[0].mtrl.tsp = 0.0;
	world->objs.v[1] = pln_crt();
	trf_ini(&trf);
	trf_rot(&trf, PI / 2.0, -PI / 4.0, 0.0);
	trf_trl(&trf, 0, 0, 5);
	trf_trf(&trf);
	obj_trf(&(world->objs.v[1]), &trf);
	world->objs.v[1].mtrl.clr = clr_unpack(BLUE);
	world->objs.v[1].mtrl.spc = 0.1;
	world->objs.v[1].mtrl.tsp = 0.0;
	world->objs.v[2] = pln_crt();
	trf_ini(&trf);
	trf_rot(&trf, PI / 2.0, PI / 4.0, PI / 6.0);
	trf_trl(&trf, 0, 0, 5);
	trf_trf(&trf);
	obj_trf(&(world->objs.v[2]), &trf);
	world->objs.v[2].mtrl.clr = clr_unpack(WHITE);
	world->objs.v[2].mtrl.spc = 0.1;
	world->objs.v[2].mtrl.tsp = 0.0;
	world->objs.v[2].mtrl.dif = 0.5;
	world->objs.v[2].mtrl.ref = 1.0;
	world->objs.v[2].mtrl.amb = 1.0;
}

// Utility function that sets up the left Sphere.
static void	setup_ele2(t_wld *world, size_t offset, t_scn *scene)
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
	world->objs.v[offset + 2].mtrl.rfl = 0.0;
	trf_ini(&trf);
	//trf_scl(&trf, 0.1, 0.1, 0.1);
	trf_trf(&trf);
	mtl_trf(&(world->objs.v[offset + 2].mtrl), &trf);
	world->objs.v[offset + 2].mtrl.tex = &(scene->texv.v[0]); // Stripe Pattern
}

// Utility function that sets up the Middle and Right Spheres.
// Sphere 4 Setup : Middle Sphere
// Sphere 5 Setup : Right Sphere
static void	setup_ele1(t_wld *world, size_t offset, t_scn *scene)
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
	//trf_rot(&trf, PI / 2.0, 0.0, 0.0);
	trf_trf(&trf);
	mtl_trf(&(world->objs.v[offset + 0].mtrl), &trf);
	world->objs.v[offset + 0].mtrl.tex = &(scene->texv.v[1]); // Gradient Pattern
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
	//trf_rot(&trf, PI / 2.0, 0.0, 0.0);
	//trf_scl(&trf, 0.01,0.01,0.01);
	trf_trf(&trf);
	mtl_trf(&(world->objs.v[offset + 1].mtrl), &trf);
	world->objs.v[offset + 1].mtrl.tex = &(scene->texv.v[3]); // Ring Pattern
}
*/