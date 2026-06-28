/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_dflt_objs_spheres.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 11:52:28 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/28 14:52:28 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Sphere 1 : Texture + BUMP
static void	setup_sphere1(t_wld *world, t_scn *scene, size_t offset)
{
	t_trf	trf;

	world->objs.v[offset] = sph_crt();
	trf_ini(&trf);
	trf_trl(&trf, 20, 0, 10);
	trf_rot(&trf, 0, 3 * PI / 4, 0);
	trf_scl(&trf, 2, 2, 2);
	trf_trf(&trf);
	obj_trf(&(world->objs.v[offset]), &trf);
	trf_ini(&trf);
	trf_trf(&trf);
	mtl_trf(&(world->objs.v[offset].mtrl), &trf);
	world->objs.v[offset].mtrl.tex = &(scene->texv.v[4]);
	world->objs.v[offset].mtrl.hmap = &(scene->hmapv.v[0]);
	world->objs.v[offset].gcord = sph_cord;
}

// Sphere 2 : Checkers
static void	setup_sphere2(t_wld *world, t_scn *scene, size_t offset)
{
	t_trf	trf;

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
}

// Sphere 3 : Stripped
static void	setup_sphere3(t_wld *world, t_scn *scene, size_t offset)
{
	t_trf	trf;

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
}

// Sphere 4 : BUMP only
static void	setup_sphere4(t_wld *world, t_scn *scene, size_t offset)
{
	t_trf	trf;

	world->objs.v[offset] = sph_crt();
	world->objs.v[offset].mtrl.clr = clr_unpack(WHITE);
	trf_ini(&trf);
	trf_trl(&trf, 5, 0, 10);
	trf_scl(&trf, 2, 2, 2);
	trf_trf(&trf);
	obj_trf(&(world->objs.v[offset]), &trf);
	trf_ini(&trf);
	trf_rot(&trf, PI / 2, 0, 0);
	trf_trf(&trf);
	mtl_trf(&(world->objs.v[offset].mtrl), &trf);
	world->objs.v[offset].mtrl.hmap = &(scene->hmapv.v[0]);
	world->objs.v[offset].gcord = sph_cord;
}

void	setup_spheres(t_wld *world, t_scn *scene, size_t offset)
{
	setup_sphere1(world, scene, offset);
	offset++;
	setup_sphere2(world, scene, offset);
	offset++;
	setup_sphere3(world, scene, offset);
	offset++;
	setup_sphere4(world, scene, offset);
	offset++;
}
