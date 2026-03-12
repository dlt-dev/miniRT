/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:30:01 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/12 12:12:49 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	cone_hit(t_cone *cone, t_ray *ray, t_hitinfo *info, t_itv *interval)
{
	(void) interval;
	t_vect3 Rl = vect3_sub(ray->o, cone->tip);
	t_vect3 Cs = vect3_sub(cone->tip, cone->bc);
	float	Ch = vect3_norm(Cs);
	t_vect3	Ca = vect3_div_scalar(Cs, Ch);
	double	Cq = (cone->r * cone->r) / (Ch * Ch);
	
	double Rd_dot_Ca = vect3_dot(ray->dir, Ca);
	double Rl_dot_Rl = vect3_dot(Rl, Rl);
	double Rl_dot_Ca = vect3_dot(Rl, Ca);

	double a = vect3_dot(ray->dir, ray->dir) - (Cq + 1) * (Rd_dot_Ca * Rd_dot_Ca);
	double b = 2 * (vect3_dot(ray->dir, Rl) - (Cq  + 1) * Rl_dot_Ca * Rd_dot_Ca);
	double c = Rl_dot_Rl - (Cq + 1) * Rl_dot_Ca * Rl_dot_Ca;

	t_tuple roots;
	int		count = quadratic_roots(a, b, c, &roots);
	if (count == 0)
		return (false);
	bool	valid1 = true;
	bool	valid2 = true;
	t_vect3	Hp1 = ray_at(*ray, roots.x);
	t_vect3 Hp2 = ray_at(*ray, roots.y);
	double	Ho1 = vect3_dot(vect3_sub(cone->tip, Hp1), Ca);
	double	Ho2 = vect3_dot(vect3_sub(cone->tip, Hp2), Ca);
	int valid_count = count;
	if (roots.x < 0.0 || Ho1 < EPS || Ho1 > Ch)
	{
		valid1 = false;
		--valid_count;
	}
	if (roots.y < 0.0 || Ho2 < EPS || Ho2 > Ch)
	{
		valid2 = false;
		if (count > 1)
			--valid_count;
	}
	if (valid_count == 0)
	{
		if (ray_disc_intersection(ray, &(cone->bc), &Ca, cone->r, &(roots.y)))
		{
			info->t = roots.y;
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
		valid2 = ray_disc_intersection(ray, &(cone->bc), &Ca, cone->r, &(roots.y));
		if (!valid2)
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