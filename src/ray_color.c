/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:14:07 by cybourge          #+#    #+#             */
/*   Updated: 2026/02/03 16:43:57 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_color	ray_color(t_ray ray)
{
	t_vect3	unit_dir;
	t_color	color_start;
	t_color	color_end;
	t_color	color_final;
	double	a;

	unit_dir = vect3_unit(ray.dir);
	a = 0.5 * (unit_dir.y + 1.0);
	color_start = trgb_unpack(0x00a6ff37);
	color_end = trgb_unpack(0x00050eb4);
	color_final.r = (1 - a) * color_start.r + a * color_end.r;
	color_final.g = (1 - a) * color_start.g + a * color_end.g;
	color_final.b = (1 - a) * color_start.b + a * color_end.b;
	color_final.t = (1 - a) * color_start.t + a * color_end.t;
	return (color_final);
}
