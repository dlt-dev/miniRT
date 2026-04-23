/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:10:29 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 17:10:51 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "transformations.h"
#include "camera.h"

/*
int	main(void)
{
	t_m44	view;
	t_m44	model;
	t_v4	from = pt_crt(0,0,0);
	t_v4	to = pt_crt(0,0,-1);
	t_v4	up = v4_crt(0, 1, 0);

	m44_vtrf(&from, &to, &up, &view);
	m44_idm(&model);
	m44_prt_uop(&view, &model, "Equality");
	
	from = pt_crt(0,0,0);
	to = pt_crt(0,0,1);
	up = v4_crt(0,1,0);
	m44_vtrf(&from, &to, &up, &view);
	m44_scl(-1, 1, -1, &model);
	m44_prt_uop(&view, &model, "Equality");

	from = pt_crt(0,0,8);
	to = pt_crt(0,0,0);
	up = v4_crt(0,1,0);
	m44_vtrf(&from, &to, &up, &view);
	m44_trl(0, 0, -8, &model);
	m44_prt_uop(&view, &model, "Equality");
	
	from = pt_crt(1,3,2);
	to = pt_crt(4,-2,8);
	up = v4_crt(1,1,0);
	m44_vtrf(&from, &to, &up, &view);
	m44_prt(&view);

	t_cam	cam1;

	cam_ini(&cam1, 125, 200, PI / 2.0);
	cam_prt(&cam1);

	t_cam	cam2;

	cam_ini(&cam2, 201, 101, PI / 2.0);
	t_ray	ray1 = cam_gen_ray(&cam2, 100, 50);
	ray_prt(&ray1);
	t_ray	ray2 = cam_gen_ray(&cam2, 0, 0);
	ray_prt(&ray2);

	t_m44	rot1;
	t_m44	trl1;
	m44_roty(PI / 4, &rot1);
	m44_trl(0, -2, 5, &trl1);
	m44_prd(&rot1, &trl1, &(cam2.vtf));
	m44_inv(&(cam2.vtf), &(cam2.ivtf));
	t_ray	ray3 = cam_gen_ray(&cam2, 100, 50);
	ray_prt(&ray3);
	return (0);
}
*/