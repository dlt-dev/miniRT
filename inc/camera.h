/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:24:47 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/01 08:03:26 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "v3.h"

typedef struct s_camera
{
	double		foc_l;
	t_v3		cam_c;
	double		vp_h;	// viewport height
	double		vp_w;	// viewport width
	t_v3		vp_u;	// viewport horizontal vector
	t_v3		vp_v;	// viewport vertical vector
	t_v3		pix_du; // viewport horizontal delta vector from pixel to pixel
	t_v3		pix_dv; // viewport vertical delta vector from pixel to pixel
	t_point		p00_lc; // position of the upper left pixel of the viewport
}			t_camera;

t_camera	camera_setup(int img_h, int img_w);

#endif