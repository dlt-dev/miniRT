/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_gen_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:15:43 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/24 09:58:26 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

// Camera viewport / canvas is at z = -1.
// Camera looks towards -z.
t_ray	cam_gen_ray(const t_cam *cam, unsigned int px, unsigned int py)
{
	t_grv	v;

	v.x_offset = (px + 0.5) * cam->pxs;
	v.y_offset = (py + 0.5) * cam->pxs;
	v.world_x = cam->hwi - v.x_offset;
	v.world_y = cam->hhe - v.y_offset;
	v.p1 = pt_crt(v.world_x, v.world_y, -1);
	v.p2 = pt_crt(0, 0, 0);
	m44_vprd(&(cam->ivtf), &v.p1, &v.pixel);
	m44_vprd(&(cam->ivtf), &v.p2, &v.origin);
	v.direction = v4_uni(v4_sub(v.pixel, v.origin));
	return ((t_ray){.o = v.origin, .dir = v.direction});
}
