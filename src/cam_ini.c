/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_ini.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:43:50 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 16:59:38 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	cam_ini(t_cam *cam, size_t hsize, size_t vsize, double fov)
{
	double	half_view;
	double	aspect;

	cam->hsz = hsize;
	cam->vsz = vsize;
	cam->fov = fov;
	half_view = tan(cam->fov / 2.0);
	aspect = cam->hsz / (double) cam->vsz;
	if (aspect >= 1.0)
	{
		cam->hwi = half_view;
		cam->hhe = half_view / aspect;
	}
	else
	{
		cam->hwi = half_view * aspect;
		cam->hhe = half_view;
	}
	cam->pxs = (cam->hwi * 2.0) / (double) cam->hsz;
	m44_idm(&(cam->vtf));
	m44_idm(&(cam->ivtf));
}
