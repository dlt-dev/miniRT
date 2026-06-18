/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_scn3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:27:43 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/18 12:21:57 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_default_mats(t_mtl *mtrl)
{
	mtrl->amb = 0.1;
	mtrl->dif = 0.9;
	mtrl->spc = 0.9;
	mtrl->shi = 200;
	mtrl->rfl = 0.0;
	mtrl->ref = 1.0;
	mtrl->tsp = 0.0;
}

static void set_default_wall(t_mtl *mtrl)
{
	t_trf	transform;
	
	mtrl->spc = 0.0;
	trf_ini(&transform);
	trf_scl(&transform, 0.5, 0.5, 0.5);
	trf_trf(&transform);
	pat_trf(&(mtrl->pat), &transform);
	mtrl->pat.pat = pat_chkr1;
	mtrl->pat.clr1 = clr_crt(0.0, 0.0, 0.0, 0.0);
	mtrl->pat.clr2 = clr_crt(0.0, 0.75, 0.75, 0.75);
}

int test_scn3(t_scn *scene)
{
	// Camera setup
	t_cam		*cam = &(scene->camera);
	const t_pt	from = pt_crt(0, 5, -40);
	const t_pt	to = pt_crt(0.0, 0, 1.0);
	const t_pt	up = v4_crt(0, 1, 0);
	cam_ini(cam, WIN_W, WIN_H, 0.5);
	m44_vtrf(&from, &to, &up, &(cam->vtf));
	m44_inv(&(cam->vtf), &(cam->ivtf));
	
	// Light Sources
	t_lgtv		lights = lgtv_crt(1);
	if (lights.cap == 0)
		return (-1);
	lights.len = 1;
	lgt_set(&(lights.v[0]), pt_crt(-5, 10, -3), WHITE);
	scene->world.lgts = lights;

	// Ambient Light
	scene->world.amb.clr = clr_unpack(WHITE);
	scene->world.amb.intensity = 0.5;

	// Object Setup 
	scene->world.objs = objv_crt(1);
	if (scene->world.objs.cap == 0)
		return (-1);
	scene->world.objs.len = 1;
	// Transformation structure to hold transformations of objects
	t_trf	transforms;
	// Index to keep track of which object we are working on
	int		index = 0;

	// Plane
	// t_obj	*plane = &(scene->world.objs.v[index]);
	// *plane = pln_crt();
	// set_default_mats(&(plane->mtrl));
	// set_default_wall(&(plane->mtrl));
	// trf_ini(&transforms);
	// trf_trl(&transforms, 0, 0, 0);
	// trf_trf(&transforms);
	// obj_trf(plane, &transforms);
	// plane->mtrl.rfl = 0.1;
	// plane->mtrl.tsp = 1.0;
	// m44_idm(&plane->mtrl.pat.tm);
	// m44_idm(&plane->mtrl.pat.itm);
	// plane->mtrl.pat.pat = pat_sphckr;
	// plane->mtrl.pat.clr1 = clr_unpack(WHITE);
	// plane->mtrl.pat.clr2 = clr_unpack(BLACK);
	// index++;

	// Cylinder Test
	// t_obj	*cylinder = &(scene->world.objs.v[index]);
	// *cylinder = cld_crt();
	// trf_ini(&transforms);
	// trf_rot(&transforms, PI/8.0, 0, PI/6.0);
	// trf_trl(&transforms, 0, 3, 0);
	// trf_scl(&transforms, 1, 10, 1);
	// trf_trf(&transforms);
	// obj_trf(cylinder, &transforms);
	// trf_ini(&transforms);
	// trf_scl(&transforms, 0.5, 0.5, 0.5);
	// trf_trf(&transforms);
	// pat_trf(&(cylinder->mtrl.pat), &transforms);
	// cylinder->mtrl.pat.pat = pat_chkr1;
	// cylinder->mtrl.pat.clr1 = clr_unpack(WHITE);
	// cylinder->mtrl.pat.clr2 = clr_unpack(BLACK);
	// index++;

	// Sphere test
	// t_obj	*sphere = &(scene->world.objs.v[index]);
	// *sphere = sph_crt();
	// trf_ini(&transforms);
	// //trf_rot(&transforms, PI/2.0, 0, PI/6.0);
	// trf_trl(&transforms, 0, 0, 0);
	// trf_scl(&transforms, 10, 10, 10);
	// trf_trf(&transforms);
	// obj_trf(sphere, &transforms);
	// trf_ini(&transforms);
	// trf_scl(&transforms, 0.01, 0.01, 0.01);
	// trf_trf(&transforms);
	// pat_trf(&(sphere->mtrl.pat), &transforms);
	// // m44_idm(&sphere->mtrl.pat.tm);
	// // m44_idm(&sphere->mtrl.pat.itm);
	// sphere->mtrl.pat.pat = pat_chkr1;
	// sphere->mtrl.pat.clr1 = clr_unpack(WHITE);
	// sphere->mtrl.pat.clr2 = clr_unpack(BLACK);
	// index++;
	
	//Cone Test
	t_obj	*cone = &(scene->world.objs.v[index]);
	*cone = con_crt();
	trf_ini(&transforms);
	//trf_rot(&transforms, 0,0,0);
	trf_trl(&transforms, 0, 0, 0);
	trf_scl(&transforms, 1, 5, 1);
	trf_trf(&transforms);
	obj_trf(cone, &transforms);
	trf_ini(&transforms);
	trf_scl(&transforms, 0.5, 0.5, 0.5);
	trf_trf(&transforms);
	pat_trf(&(cone->mtrl.pat), &transforms);
	cone->mtrl.pat.pat = pat_chkr1;
	cone->mtrl.pat.clr1 = clr_unpack(WHITE);
	cone->mtrl.pat.clr2 = clr_unpack(BLACK);
	index++;

	return (0);
}