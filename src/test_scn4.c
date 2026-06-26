/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_scn4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:17:31 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/26 10:11:36 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	test_scn4(t_scn *scene)
{
	t_cam		*cam = &(scene->camera);
	const t_pt	from = pt_crt(0.0, 1.0, -10);
	const t_v4	dir = v4_crt(0,0,1);
	const t_pt	to = v4_add(from, dir);
	const t_pt	up = v4_crt(0, 1, 0);
	cam_ini(cam, WIN_W, WIN_H, 70 * (PI / 180.0));
	m44_vtrf(&from, &to, &up, &(cam->vtf));
	m44_inv(&(cam->vtf), &(cam->ivtf));
	
	// Light Sources
	t_lgtv		lights = lgtv_crt(1);
	if (lights.cap == 0)
		return (-1);
	lights.len = 1;
	lgt_set(&(lights.v[0]), pt_crt(5, 10, -10), WHITE);
	scene->world.lgts = lights;

	// Ambient Light
	scene->world.amb.intensity = 0.5;
	scene->world.amb.clr = clr_mul(clr_unpack(WHITE), scene->world.amb.intensity);

	// Object Setup 
	scene->world.objs = objv_crt(2);
	if (scene->world.objs.cap == 0)
		return (-1);
	scene->world.objs.len = 2;
	// Transformation structure to hold transformations of objects
	t_trf	transforms;
	// Index to keep track of which object we are working on
	int		index = 0;

	// Sphere
	t_obj	*sphere = &(scene->world.objs.v[index]);
	*sphere = sph_crt();
	sphere->mtrl.clr = clr_crt(0, 1.0, 0, 0);
	trf_ini(&transforms);
	trf_trl(&transforms, 0, 3, 0);
	trf_scl(&transforms, 0.5, 0.5, 0.5);
	trf_trf(&transforms);
	obj_trf(sphere, &transforms);
	// if (ftex_load(&(sphere->mtrl.tex), "earth.xpm", &(scene->mlx)) == -1)
	// 	return (1);
	// trf_ini(&transforms);
	// trf_scl(&transforms, 1, 1, 1);
	// trf_rot(&transforms, 0, 0, PI);
	// trf_trf(&transforms);
	// pat_trf(&(sphere->mtrl.pat), &transforms);
	// sphere->mtrl.pat.pat = pat_chkr1;
	// sphere->mtrl.pat.clr1 = clr_unpack(WHITE);
	// sphere->mtrl.pat.clr2 = clr_unpack(RED);
	index++;

	// Plane
	t_obj	*plane = &(scene->world.objs.v[index]);
	*plane = pln_crt();
	plane->mtrl.clr = clr_crt(0, 0, 1.0, 0);
	plane->mtrl.amb = 1.0;
	plane->mtrl.spc = 0.0;
	plane->mtrl.dif = 0.0;
	plane->mtrl.shi = 200;
	plane->mtrl.rfl = 1.0;
	plane->mtrl.tsp = 0;
	plane->mtrl.ref = 1.57;
	trf_ini(&transforms);
	trf_trl(&transforms, 0, -1, 0);
	//trf_scl(&transforms, 1, 5, 2);
	trf_trf(&transforms);
	obj_trf(plane, &transforms);
	// trf_ini(&transforms);
	// trf_scl(&transforms, 100, 100, 100);
	// trf_trf(&transforms);
	// pat_trf(&(plane->mtrl.pat), &transforms);
	// if (ftex_load(&(plane->mtrl.tex), "earth.xpm", &(scene->mlx)) == -1)
	// 	return (1);
	index++;

	// Cylinder
	// t_obj	*cylinder = &(scene->world.objs.v[index]);
	// *cylinder = cld_crt();
	// trf_ini(&transforms);
	// //trf_rot(&transforms, PI/8.0, 0, PI/6.0);
	// trf_trl(&transforms, 0, 3, 0);
	// trf_scl(&transforms, 1, 5, 1);
	// trf_trf(&transforms);
	// obj_trf(cylinder, &transforms);
	// trf_ini(&transforms);
	// trf_scl(&transforms, 0.5, 0.5, 0.5);
	// trf_trf(&transforms);
	// pat_trf(&(cylinder->mtrl.pat), &transforms);
	// cylinder->mtrl.pat.pat = pat_chkr1;
	// cylinder->mtrl.pat.clr1 = clr_unpack(WHITE);
	// cylinder->mtrl.pat.clr2 = clr_unpack(RED);
	// index++;

	// Cone
	// t_obj	*cone = &(scene->world.objs.v[index]);
	// *cone = con_crt();
	// trf_ini(&transforms);
	// trf_trl(&transforms, -5, 2, 0);
	// trf_scl(&transforms, 1, 5, 1);
	// trf_trf(&transforms);
	// obj_trf(cone, &transforms);
	// trf_ini(&transforms);
	// trf_scl(&transforms, 2, 2, 2);
	// trf_trf(&transforms);
	// pat_trf(&(cone->mtrl.pat), &transforms);
	// cone->mtrl.pat.pat = pat_chkr1;
	// cone->mtrl.pat.clr1 = clr_unpack(WHITE);
	// cone->mtrl.pat.clr2 = clr_unpack(BLUE);
	// index++;
	return (0);
}