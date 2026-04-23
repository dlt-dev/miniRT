/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:14:07 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 09:58:34 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	ray_color(t_ray ray, t_mlx_data *d)
{
	t_vect3		unit_dir;
	t_color		color_start;
	t_color		color_end;
	t_color		color_final;
	t_itv		inter =  itv_crt(0.0, INFINITY);
	t_hitinfo	info;
	double		a;

	int 		i = 0;
	bool		hit_anything = false;
	while (i < NB_OBJ)
	{
		if (sphere_hit(&(d->sphere[i]), &ray, &info, &inter))
		{
			hit_anything = true;
			inter.max = info.t;
			color_final = d->sphere[i].color;
			//color_final = ((t_color) {(info.n.x + 1.0) * 0.5, (info.n.y + 1.0) * 0.5, (info.n.z + 1.0) * 0.5, 0.0});
		}
		i++;
	}
	if (cldr_hit(&(d->cylinder), &ray, &info, &inter))
	{
		if (info.front_face)
			color_final = d->cylinder.color;
		else
			color_final = trgb_unpack(0x00FF1420);
		hit_anything = true;
		inter.max = info.t;
	}
		
	// if (cone_hit(&(d->cone), &ray, &info, &inter))
	// {
	// 	color_final = d->cone.color;
	// 	hit_anything = true;
	// 	inter.max = info.t;
	// }
	if (pln_hit(&(d->plane), &ray, &info, &inter))
	{
		color_final = d->plane.color;
		hit_anything = true;
		inter.max = info.t;
	}
	if (trgl_hit(&(d->triangle), &ray, &info, &inter))
	{
		color_final = d->triangle.color;
		hit_anything = true;
		inter.max = info.t;
	}
	if (hit_anything)
		return (color_final);
	
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
