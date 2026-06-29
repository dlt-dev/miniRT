/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_dflt_obs_planes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 11:58:15 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/29 07:58:46 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Left Plane : Checkers
static void	setup_plane1(t_wld *world, t_scn *scene, size_t offset)
{
	t_trf	trf;

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
}

// Floor : Mirror
static void	setup_plane2(t_wld *world, t_scn *scene, size_t offset)
{
	t_trf	trf;

	(void) world;
	scene->world.objs.v[offset] = pln_crt();
	trf_ini(&trf);
	trf_trl(&trf, 0, -5, 0);
	scene->world.objs.v[offset].mtrl.rfl = 1.0;
	scene->world.objs.v[offset].mtrl.dif = 0.5;
	scene->world.objs.v[offset].mtrl.amb = 0.0;
	trf_trf(&trf);
	obj_trf(&(scene->world.objs.v[offset]), &trf);
}

void	setup_planes(t_wld *world, t_scn *scene, size_t offset)
{
	setup_plane1(world, scene, offset);
	offset++;
	setup_plane2(world, scene, offset);
	offset++;
}
