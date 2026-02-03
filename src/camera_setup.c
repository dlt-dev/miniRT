/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:02:17 by cybourge          #+#    #+#             */
/*   Updated: 2026/02/03 16:43:03 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera	camera_setup(int img_h, int img_w)
{
	t_camera	cam;
	t_point		vp_ul;

	cam.foc_l = 1.0;
	cam.cam_c = (t_vect3){0.0, 0.0, 0.0};
	cam.vp_h = 2.0;
	cam.vp_w = cam.vp_h * ((double)img_w / img_h);
	cam.vp_u = (t_vect3){cam.vp_w, 0.0, 0.0};
	cam.vp_v = (t_vect3){0.0, -cam.vp_h, 0.0};
	cam.pix_du = vect3_div_scalar(cam.vp_u, img_w);
	cam.pix_dv = vect3_div_scalar(cam.vp_v, img_h);
	vp_ul = vect3_sub(cam.cam_c, (t_vect3){0.0, 0.0, cam.foc_l});
	vp_ul = vect3_sub(vp_ul, vect3_div_scalar(cam.vp_u, 2.0));
	vp_ul = vect3_sub(vp_ul, vect3_div_scalar(cam.vp_v, 2.0));
	cam.p00_lc = vect3_add(vp_ul, vect3_mul_scalar(vect3_add(cam.pix_du,
					cam.pix_dv), 0.5));
	return (cam);
}
