/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_scn1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 08:01:16 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 10:57:07 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/*
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

static void	set_default_wall(t_mtl *mtrl)
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

int test_scn1(t_scn *scene)
{
	// Camera setup
	t_cam		*cam = &(scene->camera);
	const t_pt	from = pt_crt(-4.5, 0.85, -4.0);
	const t_pt	to = pt_crt(0.0, 0.85, 0.0);
	const t_pt	up = v4_crt(0, 1, 0);
	cam_ini(cam, WIN_W, WIN_H, 0.5);
	m44_vtrf(&from, &to, &up, &(cam->vtf));
	m44_inv(&(cam->vtf), &(cam->ivtf));
	
	// Light Sources
	t_lgtv		lights = lgtv_crt(1);
	if (lights.cap == 0)
		return (-1);
	lights.len = 1;
	lgt_set(&(lights.v[0]), pt_crt(-4.9, 4.9, 1), WHITE);
	scene->world.lgts = lights;

	// Ambient Light
	scene->world.amb.clr = clr_unpack(BLACK);
	scene->world.amb.intensity = 0.0;

	// Object Setup 
	scene->world.objs = objv_crt(10);
	if (scene->world.objs.cap == 0)
		return (-1);
	scene->world.objs.len = 10;
	// Transformation structure to hold transformations of objects
	t_trf	transforms;
	// Index to keep track of which object we are working on
	int		index = 0;
	
	// Floor setup
	t_obj	*floor = &(scene->world.objs.v[index]);
	*floor = pln_crt();
	set_default_mats(&(floor->mtrl));
	trf_ini(&transforms);
	trf_rot(&transforms, 0.0, 0.31415, 0.0);
	trf_trf(&transforms);
	obj_trf(floor, &transforms);
	floor->mtrl.amb = 0.5;
	floor->mtrl.dif = 0.4;
	floor->mtrl.spc = 0.8;
	floor->mtrl.rfl = 0.1;
	floor->mtrl.pat.pat = pat_chkr1;
	floor->mtrl.pat.clr1 = clr_crt(0.0, 0.0, 0.0, 0.0);
	floor->mtrl.pat.clr2 = clr_crt(0.0, 0.75, 0.75, 0.75);
	m44_idm(&(floor->mtrl.pat.tm));
	m44_idm(&(floor->mtrl.pat.itm));
	index++;

	// Ceiling Setup
	t_obj	*ceiling = &(scene->world.objs.v[index]);
	*ceiling = pln_crt();
	set_default_mats(&(ceiling->mtrl));
	trf_ini(&transforms);
	trf_trl(&transforms, 0, 5, 0);
	trf_trf(&transforms);
	obj_trf(ceiling, &transforms);
	ceiling->mtrl.amb = 0.5;
	ceiling->mtrl.spc = 0;
	ceiling->mtrl.pat.pat = pat_chkr1;
	ceiling->mtrl.pat.clr1 = clr_crt(0.0, 0.85, 0.85, 0.85);
	ceiling->mtrl.pat.clr2 = clr_crt(0.0, 1.0, 1.0, 1.0);
	trf_ini(&transforms);
	trf_scl(&transforms, 0.2, 0.2, 0.2);
	trf_trf(&transforms);
	pat_trf(&(ceiling->mtrl.pat), &transforms);
	index++;

	// West Wall Setup
	t_obj	*west_wall = &(scene->world.objs.v[index]);
	*west_wall = pln_crt();
	set_default_mats(&(west_wall->mtrl));
	set_default_wall(&(west_wall->mtrl));
	trf_ini(&transforms);
	trf_rot(&transforms, 0.0, 1.5708, 1.5708);
	trf_trl(&transforms, -5, 0, 0);
	trf_trf(&transforms);
	obj_trf(west_wall, &transforms);
	index++;

	// East Wall Setup
	t_obj	*east_wall = &(scene->world.objs.v[index]);
	*east_wall = pln_crt();
	set_default_mats(&(east_wall->mtrl));
	set_default_wall(&(east_wall->mtrl));
	trf_ini(&transforms);
	trf_rot(&transforms, 0.0, 1.5708, 1.5708);
	trf_trl(&transforms, 5, 0, 0);
	trf_trf(&transforms);
	obj_trf(east_wall, &transforms);
	index++;
	
	// North Wall Setup
	t_obj	*north_wall = &(scene->world.objs.v[index]);
	*north_wall = pln_crt();
	set_default_mats(&(north_wall->mtrl));
	set_default_wall(&(north_wall->mtrl));
	trf_ini(&transforms);
	trf_rot(&transforms, 1.5708, 0.0, 0.0);
	trf_trl(&transforms, 0, 0, 5);
	trf_trf(&transforms);
	obj_trf(north_wall, &transforms);
	index++;

	// South Wall Setup
	t_obj	*south_wall = &(scene->world.objs.v[index]);
	*south_wall = pln_crt();
	set_default_mats(&(south_wall->mtrl));
	set_default_wall(&(south_wall->mtrl));
	trf_ini(&transforms);
	trf_rot(&transforms, 1.5708, 0.0, 0.0);
	trf_trl(&transforms, 0, 0, -5);
	trf_trf(&transforms);
	obj_trf(south_wall, &transforms);
	index++;

	// Background Ball 1
	t_obj	*bg_ball1 = &(scene->world.objs.v[index]);
	*bg_ball1 = sph_crt();
	set_default_mats(&(bg_ball1->mtrl));
	trf_ini(&transforms);
	trf_trl(&transforms, 4, 1, 4);
	trf_trf(&transforms);
	obj_trf(bg_ball1, &transforms);
	bg_ball1->mtrl.clr = clr_crt(0.0, 0.8, 0.1, 0.3);
	bg_ball1->mtrl.spc = 0;
	index++;
	
	// Background Ball 2
	t_obj	*bg_ball2 = &(scene->world.objs.v[index]);
	*bg_ball2 = sph_crt();
	set_default_mats(&(bg_ball2->mtrl));
	trf_ini(&transforms);
	trf_scl(&transforms, 0.4, 0.4, 0.4);
	trf_trl(&transforms, 4.6, 0.4, 2.9);
	trf_trf(&transforms);
	obj_trf(bg_ball2, &transforms);
	bg_ball2->mtrl.clr = clr_crt(0.0, 0.1, 0.8, 0.2);
	bg_ball2->mtrl.shi = 200;
	index++;
	
	// Background Ball 3
	t_obj	*bg_ball3 = &(scene->world.objs.v[index]);
	*bg_ball3 = sph_crt();
	set_default_mats(&(bg_ball3->mtrl));
	trf_ini(&transforms);
	trf_scl(&transforms, 0.6, 0.6, 0.6);
	trf_trl(&transforms, 2.6, 0.6, 4.4);
	trf_trf(&transforms);
	obj_trf(bg_ball3, &transforms);
	bg_ball3->mtrl.clr = clr_crt(0.0, 0.2, 0.1, 0.8);
	bg_ball3->mtrl.shi = 10;
	bg_ball3->mtrl.spc = 0.4;
	index++;

	// Glass Ball
	t_obj	*glass_ball = &(scene->world.objs.v[index]);
	*glass_ball = sph_crt();
	set_default_mats(&(glass_ball->mtrl));
	trf_ini(&transforms);
	trf_scl(&transforms, 1.0, 1.0, 1.0);
	trf_trl(&transforms, 0.25, 1.0, 0);
	trf_trf(&transforms);
	obj_trf(glass_ball, &transforms);
	glass_ball->mtrl.clr = clr_crt(0.0, 0.8, 0.8, 0.9);
	glass_ball->mtrl.amb = 0;
	glass_ball->mtrl.dif = 0.2;
	glass_ball->mtrl.spc = 0.9;
	glass_ball->mtrl.shi = 300;
	glass_ball->mtrl.tsp = 0.8;
	glass_ball->mtrl.ref = 1.57;
	index++;
	
	return (0);
}
*/