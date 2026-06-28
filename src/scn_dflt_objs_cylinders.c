/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_dflt_objs_cylinders.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 12:01:18 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/28 12:05:32 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Cylinder 1 : Checkers
static void	setup_cylinder1(t_wld *world, t_scn *scene, size_t offset)
{
	t_trf	trf;

	scene->world.objs.v[offset] = cld_crt();
	trf_ini(&trf);
	trf_rot(&trf, -PI / 8, 0, PI / 2);
	trf_trl(&trf, 20, 5, 0);
	trf_scl(&trf, 0.5, 10, 0.5);
	trf_trf(&trf);
	obj_trf(&(scene->world.objs.v[offset]), &trf);
	trf_ini(&trf);
	trf_scl(&trf, 0.7, 0.7, 0.7);
	trf_trf(&trf);
	mtl_trf(&(world->objs.v[offset].mtrl), &trf);
	world->objs.v[offset].mtrl.tex = &(scene->texv.v[3]);
	world->objs.v[offset].gcord = cld_cord;
}

// Cylinder 2 : Mirror
static void	setup_cylinder2(t_wld *world, t_scn *scene, size_t offset)
{
	t_trf	trf;

	scene->world.objs.v[offset] = cld_crt();
	trf_ini(&trf);
	trf_trl(&trf, 12.5, 15, 10);
	trf_rot(&trf, PI / 4, 0, 0);
	trf_scl(&trf, 7, 0.25, 7);
	trf_trf(&trf);
	obj_trf(&(scene->world.objs.v[offset]), &trf);
	trf_ini(&trf);
	trf_scl(&trf, 0.7, 0.7, 0.7);
	trf_trf(&trf);
	mtl_trf(&(world->objs.v[offset].mtrl), &trf);
	scene->world.objs.v[offset].mtrl.rfl = 1.0;
	scene->world.objs.v[offset].mtrl.dif = 0.5;
	scene->world.objs.v[offset].mtrl.amb = 0.0;
	world->objs.v[offset].gcord = cld_cord;
}

// Cone 1 : Gradient
static void	setup_cylinder3(t_wld *world, t_scn *scene, size_t offset)
{
	t_trf	trf;

	scene->world.objs.v[offset] = con_crt();
	trf_ini(&trf);
	trf_rot(&trf, 0, PI, -PI / 2);
	trf_trl(&trf, 10, 5, 0);
	trf_scl(&trf, 1, 5, 1);
	trf_trf(&trf);
	obj_trf(&(scene->world.objs.v[offset]), &trf);
	trf_ini(&trf);
	trf_scl(&trf, 1, 1, 1);
	trf_trf(&trf);
	mtl_trf(&(world->objs.v[offset].mtrl), &trf);
	world->objs.v[offset].mtrl.tex = &(scene->texv.v[1]);
	world->objs.v[offset].gcord = con_cord;
}

void	setup_cylinders(t_wld *world, t_scn *scene, size_t offset)
{
	setup_cylinder1(world, scene, offset);
	offset++;
	setup_cylinder2(world, scene, offset);
	offset++;
	setup_cylinder3(world, scene, offset);
	offset++;
}
