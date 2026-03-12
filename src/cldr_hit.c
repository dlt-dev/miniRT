/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cldr_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 09:39:09 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/12 11:43:37 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	cldr_hit(t_cldr *cyl, t_ray *ray, t_hitinfo *info, t_itv *interval)
{
	(void) interval;
	t_vect3	Rl = vect3_sub(ray->o, cyl->end_cap_b);
	//t_vect3 Cs = vect3_sub(cyl->end_cap_t, cyl->end_cap_b);
	double	Ch = cyl->h;
	t_vect3 Ca = cyl->axis;
	
	ray->dir = vect3_unit(ray->dir);
	double	Ca_dot_Rd = vect3_dot(Ca, ray->dir);
	double	Ca_dot_Rl = vect3_dot(Ca, Rl);
	double	Rl_dot_Rl = vect3_dot(Rl, Rl);

	double	a = 1 - (Ca_dot_Rd * Ca_dot_Rd);
	double	b = 2 * (vect3_dot(ray->dir, Rl) - Ca_dot_Rd * Ca_dot_Rl);
	double	c = Rl_dot_Rl - (Ca_dot_Rl * Ca_dot_Rl) - (cyl->d / 2.0) * (cyl->d / 2.0);
	
	t_tuple	roots;
	int		count;

	count = quadratic_roots(a, b, c, &roots);
	if (count == 0)
		return (false);
	bool	valid1 = true;
	bool	valid2 = true;
	t_vect3	Hp1 = ray_at(*ray, roots.x);
	t_vect3	Hp2 = ray_at(*ray, roots.y);
	double	Ho1 = vect3_dot(vect3_sub(cyl->end_cap_t, Hp1), Ca);
	double	Ho2 = vect3_dot(vect3_sub(cyl->end_cap_t, Hp2), Ca);
	int		valid_count = count;
	if (roots.x < 0.0 || Ho1 < EPS || Ho1 > Ch)
	{
		valid1 = false;
		--valid_count;
	}
	if (roots.y < 0.0 || Ho2 < EPS || Ho2 > Ch)
	{
		valid2 = false;
		if (valid_count > 0)
			--valid_count;
	}
	if (valid_count == 0)
	{
		if (Ca_dot_Rl <= 0.0)
			valid1 = ray_disc_intersection(ray, &(cyl->end_cap_t), &Ca, cyl->d / 2.0, &(roots.x));
		else if (Ca_dot_Rl > Ch )
			valid1 = ray_disc_intersection(ray, &(cyl->end_cap_b), &Ca, cyl->d / 2.0, &(roots.y));
		else
		{
			valid1 = ray_disc_intersection(ray, &(cyl->end_cap_t), &Ca, cyl->d / 2.0, &(roots.x));
        	valid2 = ray_disc_intersection(ray, &(cyl->end_cap_b), &Ca, cyl->d / 2.0, &(roots.y));
			if (valid1)
			{
				if (valid2)
				{
					if (roots.y < roots.x)
						roots.x = roots.y;
				}
				info->t = roots.x;
				return (true);
			}
			else if (valid2)
			{
				info->t = roots.y;
				return (true);
			}
		}
		if (valid1)
		{
			info->t = roots.x;
			return (true);
		}
		return (false);		
	}
	if (valid_count == 1)
	{
		if (valid2)
		{
			Hp1 = Hp2;
			Ho1 = Ho2;
			valid1 = true;
			roots.x = roots.y;
		}
		double	disc_near;
		double	disc_away;
		bool	disc1 = ray_disc_intersection(ray, &(cyl->end_cap_t), &Ca, cyl->d / 2.0, &disc_near);
		bool	disc2 = ray_disc_intersection(ray, &(cyl->end_cap_b), &Ca, cyl->d / 2.0, &disc_away);
		if (disc1)
		{
			if (disc2)
				if (disc_away < disc_near)
					disc_near = disc_away;
		}
		else if (disc2)
		{
			disc_near = roots.y;
			disc1 = disc2;
		}
		if (disc1)
		{
			if (disc_near < roots.x)
			{
				info->t = roots.x;
				return (true);
			}
		}
		else
		{
			info->t = roots.x;
			return (true);
		}
	}
	if (roots.x > roots.y)
		info->t = roots.y;
	else
		info->t = roots.x;
	return (true);
}