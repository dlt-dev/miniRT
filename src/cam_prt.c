/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_prt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:45:28 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/30 09:27:18 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	cam_prt(const t_cam *cam)
{
	printf("Camera (%ld x %ld) :\n", cam->hsz, cam->vsz);
	printf("FOV: %lf, Half-Width: %lf, Half-Height: %lf, Pixel Size: %lf\n",
		cam->fov, cam->hwi, cam->hhe, cam->pxs);
	printf("Camera Transformation Matrix :\n");
	m44_prt(&(cam->vtf));
	printf("Camera Inverse Transformation Matrix : \n");
	m44_prt(&(cam->ivtf));
}
