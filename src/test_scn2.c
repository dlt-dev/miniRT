/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_scn2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:00:54 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 10:57:16 by cybourge         ###   ########.fr       */
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

static void set_default_wall(t_mtl *mtrl)
{
	t_trf	transform;
	
	mtrl->spc = 0.0;
	trf_ini(&transform);
	trf_scl(&transform, 0.5, 0.5, 0.5);
	trf_trf(&transform);
	pat_trf(&(mtrl->pat), &transform);
	mtrl->pat.pat = NULL;
	mtrl->clr = clr_unpack(BLACK);
	mtrl->pat.clr1 = clr_crt(0.0, 0.0, 0.0, 0.0);
	mtrl->pat.clr2 = clr_crt(0.0, 0.75, 0.75, 0.75);
}

int test_scn2(t_scn *scene)
{
	// Camera setup
	t_cam		*cam = &(scene->camera);
	const t_pt	from = pt_crt(0, 2.0, -5);
	const t_pt	to = pt_crt(0.0, -0.5, 0.0);
	const t_pt	up = v4_crt(0, 1, 0);
	cam_ini(cam, WIN_W, WIN_H, 0.5);
	m44_vtrf(&from, &to, &up, &(cam->vtf));
	m44_inv(&(cam->vtf), &(cam->ivtf));
	
	// Light Sources
	t_lgtv		lights = lgtv_crt(1);
	if (lights.cap == 0)
		return (-1);
	lights.len = 1;
	lgt_set(&(lights.v[0]), pt_crt(0, 0, 0), WHITE);
	scene->world.lgts = lights;

	// Ambient Light
	scene->world.amb.clr = clr_unpack(BLACK);
	scene->world.amb.intensity = 0.0;

	// Object Setup 
	scene->world.objs = objv_crt(2);
	if (scene->world.objs.cap == 0)
		return (-1);
	scene->world.objs.len = 2;
	// Transformation structure to hold transformations of objects
	t_trf	transforms;
	// Index to keep track of which object we are working on
	int		index = 0;

	// East Wall Setup
	t_obj	*east_wall = &(scene->world.objs.v[index]);
	*east_wall = pln_crt();
	set_default_mats(&(east_wall->mtrl));
	set_default_wall(&(east_wall->mtrl));
	trf_ini(&transforms);
	trf_trl(&transforms, 0, -0.5, 0);
	trf_trf(&transforms);
	obj_trf(east_wall, &transforms);
	east_wall->mtrl.rfl = 1.0;
	index++;

	// Background Ball 3
	t_obj	*bg_ball3 = &(scene->world.objs.v[index]);
	*bg_ball3 = sph_crt();
	set_default_mats(&(bg_ball3->mtrl));
	trf_ini(&transforms);
	trf_scl(&transforms, 0.5, 0.5, 0.5);
	trf_trl(&transforms, 0, 0, 0);
	trf_trf(&transforms);
	obj_trf(bg_ball3, &transforms);
	bg_ball3->mtrl.clr = clr_crt(0.0, 0.2, 0.1, 0.8);
	bg_ball3->mtrl.shi = 10;
	bg_ball3->mtrl.spc = 0.4;
	bg_ball3->mtrl.tsp = 1.0;
	index++;

	return (0);
}
*/