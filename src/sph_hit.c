/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sph_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:40:23 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/03 10:19:48 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	sph_hit(const t_sph *sp, const t_ray *r, t_tpl *hit_res)
{
	t_v4	sp_ray;
	double	a;
	double	b;
	double	c;
	double	d;

	sp_ray = v4_sub(r->o, sp->c);
	a = v4_dot(r->dir, r->dir);
	b = 2 * v4_dot(r->dir, sp_ray);
	c = v4_dot(sp_ray, sp_ray) - 1;
	d = b * b - 4 * a * c;
	if (d >= 0)
	{
		hit_res->x = (-b - sqrt(d)) / (2 * a);
		hit_res->y = (-b + sqrt(d)) / (2 * a);
		tpl_sort(hit_res);
		return (true);
	}
	hit_res->x = NAN;
	hit_res->y = NAN;
	return (false);
}
