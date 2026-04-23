/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:24:47 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 17:07:32 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "matrix.h"
# include "ray.h"
# include "world.h"

// hsz : Horizontal size (Pixels)
// vsz : Vertical size (Pixels)
// fov : Field of View (Radiant)
// hwi  : Half-Width
// hhe  : Half-Height
// pxs : Pixel Size
// vtf : View Transform Matrix
// ivtf : Inverse of the View Transform Matrix.
typedef struct s_camera
{
	size_t	hsz;
	size_t	vsz;
	double	fov;
	double	hwi;
	double	hhe;
	double	pxs;
	t_m44	vtf;
	t_m44	ivtf;
}	t_cam;

// Creates a camera with identity matrix as its default view transform.
void	cam_ini(t_cam *cam, size_t hsize, size_t vsize, double fov);

// Displays the camera.
void	cam_prt(const t_cam *cam);

// Generates a ray that passes through the pixel P(px,py).
t_ray	cam_gen_ray(const t_cam *cam, unsigned int px, unsigned int py);

#endif