/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:14:07 by cybourge          #+#    #+#             */
/*   Updated: 2026/02/04 14:31:15 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "object.h"

t_color	ray_color(t_ray ray, t_sphere *sphere)
{
	t_vect3	unit_dir;
	t_color	color_start;
	t_color	color_end;
	t_color	color_final;
	double	a;
	double	t;

	int i = 0;
	while (i < 3)
	{
		t = sphere_is_hit(&(sphere[i]), &ray);
		if (t > 0.0)
		{
			t_vect3 norm = vect3_unit(vect3_sub(ray_at(ray, t), sphere[i].c));
			return ((t_color) {(norm.x + 1.0) * 0.5, (norm.y + 1.0) * 0.5, (norm.z + 1.0) * 0.5, 0.0});
		}
		i++;
	}
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
