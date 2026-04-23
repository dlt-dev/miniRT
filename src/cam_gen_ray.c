/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_gen_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:15:43 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 17:04:11 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

// Camera viewport / canvas is at z = -1.
// Camera looks towards -z.
t_ray	cam_gen_ray(const t_cam *cam, unsigned int px, unsigned int py)
{
	const double	x_offset = (px + 0.5) * cam->pxs;
	const double	y_offset = (py + 0.5) * cam->pxs;
	const double	world_x = cam->hwi - x_offset;
	const double	world_y = cam->hhe - y_offset;
	t_pt			pixel;
	t_pt			origin;
	t_v4			direction;
	t_pt			p1;
	t_pt			p2;
	
	p1 = pt_crt(world_x, world_y, -1);
	p2 = pt_crt(0, 0, 0);
	m44_vprd(&(cam->ivtf), &p1, &pixel);
	m44_vprd(&(cam->ivtf), &p2, &origin);
	direction = v4_uni(v4_sub(pixel, origin));
	return ((t_ray){.o = origin, .dir = direction});
}
