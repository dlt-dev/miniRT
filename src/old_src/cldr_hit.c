/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cldr_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 09:39:09 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 09:58:19 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


typedef struct quad_roots
{
	double	r1;
	double	r2;
	int		nb_roots;
}	t_qr;

// Allows to pass multiple arguments as one : 42 Norm constraint
typedef struct cylinder_intersection_data
{
	const t_cldr	*cyl;
	const t_ray		*ray;
	const t_itv		*inter;
}	t_cldr_idata;

static
int	inf_cyl_roots(const t_cldr *cyl, const t_ray *ray, t_tuple *res)
{
	const t_vect3	rl = vect3_sub(ray->o, cyl->capb);
	const double	ca_dot_rd = vect3_dot(cyl->axis, ray->dir);
	const double	ca_dot_rl = vect3_dot(cyl->axis, rl);
	const double	rl_dot_rl = vect3_dot(rl, rl);

	return (quadratic_roots(
		1 - (ca_dot_rd * ca_dot_rd),
		2 * (vect3_dot(ray->dir, rl) - ca_dot_rd * ca_dot_rl),
		rl_dot_rl - (ca_dot_rl * ca_dot_rl) - (cyl->r) * (cyl->r),
		res
		));
}

static
void	set_root(const t_cldr_idata *data, t_qr *rts, double r)
{
	const t_itv	cyl_bounds =  itv_crt(0.0, data->cyl->h);
	t_vect3		c_to_hp;
	
	if (!isnan(r) && r > 0.0)
	{
		c_to_hp = vect3_sub(data->cyl->capt, ray_at(*(data->ray), r));
		if (itv_contains(&cyl_bounds, vect3_dot(c_to_hp, data->cyl->axis)))
		{
			if (rts->nb_roots == 0)
				rts->r1 = r;
			else
				rts->r2 = r;
			rts->nb_roots++;
		}
	}
}

static	void	qr_sort(t_qr *rts)
{
	double	tmp;

	if (rts->nb_roots == 1 && isnan(rts->r1))
	{
		rts->r1 = rts->r2;
		rts->r2 = NAN;
	}
	else if (rts->nb_roots == 2 && rts->r1 > rts->r2)
	{
		tmp = rts->r2;
		rts->r2 = rts->r1;
		rts->r1 = tmp;
	}
}

static
int	cyl_rts(const t_cldr *cyl, const t_ray *ray, t_qr *rts)
{
	const t_cldr_idata	data = (t_cldr_idata){(t_cldr *)cyl, (t_ray *)ray, 0};
	int					root_count;
	t_tuple				result;

	*rts = (t_qr){NAN, NAN, 0};
	result = (t_tuple){NAN, NAN};
	root_count = inf_cyl_roots(cyl, ray, &result);
	set_root(&data, rts, result.x);
	set_root(&data, rts, result.y);
	qr_sort(rts);
	return (root_count);
}

static
int	cap_rts(const t_cldr *cyl, const t_ray *ray, t_qr *rts)
{
	rts->nb_roots = 0;
	if (rd_int(ray, &(cyl->capb), &(cyl->axis), cyl->r, &(rts->r1)))
	{
		rts->nb_roots++;
		printf("WTF1\n");
	}
		
	if (rts->nb_roots == 0)
	{
		if (rd_int(ray, &(cyl->capt), &(cyl->axis), cyl->r, &(rts->r1)))
		{
			rts->nb_roots++;
			printf("WTF2\n");
		}
	}
	else
	{
		if (rd_int(ray, &(cyl->capt), &(cyl->axis), cyl->r, &(rts->r2)))
		{
			rts->nb_roots++;
			printf("WTF3\n");
		}
	}
	qr_sort(rts);
	if (rts->nb_roots == 2)
		printf("Bro what\n");
	return (rts->nb_roots);
}

// returns the minimum between 2 root tuples, NAN if they're not defined
// sets the boolean to indicate if the min is in the cap or not
static double qr_min(const t_qr *cyl_r, const t_qr *cap_r, bool *is_cap_r)
{
	if (isnan(cyl_r->r1))
	{
		if (isnan(cap_r->r1))
		{
			*is_cap_r = false;
			return (NAN);
		}
		else
		{
			*is_cap_r = true;
			return (cap_r->r1);
		}
	}
	if (isnan(cap_r->r1))
	{
		*is_cap_r = false;
		return (cyl_r->r1);
	}
	else if (cyl_r->r1 < cap_r->r1)
	{
		*is_cap_r = false;
		return (cyl_r->r1);
	}
	else
	{
		*is_cap_r = true;
		return (cap_r->r1);
	}
}

static t_vect3	cldr_surf_normal(const t_cldr *cyl, const t_hitinfo *info)
{
	t_vect3	v;
	t_vect3	va;
	t_vect3	vn;

	v = vect3_sub(info->p, cyl->c);
	va = vect3_mul_scalar(cyl->axis, vect3_dot(v, cyl->axis));
	vn = vect3_sub(v, va);
	vn = vect3_unit(vn);
	if (info->front_face)
		return (vn);
	else
		return (vect3_inv(vn));
}


bool	cldr_hit(t_cldr *cyl, t_ray *ray, t_hitinfo *info, t_itv *interval)
{
	t_qr	cyl_rs;
	t_qr	cap_rs;
	bool	is_cap_rs;
	double	min_rs;
	int		total_rs;

	cyl_rs = (t_qr){NAN, NAN, 0};
	cap_rs = (t_qr){NAN, NAN, 0};
	total_rs = cyl_rts(cyl, ray, &cyl_rs);
	if (total_rs < 2)
		total_rs += cap_rts(cyl, ray, &cap_rs);
	min_rs = qr_min(&cyl_rs, &cap_rs, &is_cap_rs);
	if (total_rs == 0 || !itv_contains(interval, min_rs))
		return (false);
	info->t = min_rs;
	info->p = ray_at(*ray, info->t);
	if ((cyl_rs.nb_roots == 1 && cap_rs.nb_roots == 0))
		info->front_face = false;
	else if (cyl_rs.nb_roots == 0 && cap_rs.nb_roots == 1)
		info->front_face = false;
	else
		info->front_face = true;
	if (is_cap_rs && info->front_face)
		info->n = vect3_inv(cyl->axis);
	else if (is_cap_rs && !info->front_face)
		info->n = cyl->axis;
	else // get the normal to a point on the sides of a cylinder
		info->n = cldr_surf_normal(cyl, info);
	return (true);
}


/*
bool	cldr_hit(t_cldr *cyl, t_ray *ray, t_hitinfo *info, t_itv *interval)
{
	t_vect3	rl = vect3_sub(ray->o, cyl->capb);
	double	ca_dot_rd = vect3_dot(cyl->axis, ray->dir);
	double	ca_dot_rl = vect3_dot(cyl->axis, rl);
	double	rl_dot_rl = vect3_dot(rl, rl);

	double	a = 1 - (ca_dot_rd * ca_dot_rd);
	double	b = 2 * (vect3_dot(ray->dir, rl) - ca_dot_rd * ca_dot_rl);
	double	c = rl_dot_rl - (ca_dot_rl * ca_dot_rl) - (cyl->r) * (cyl->r);
	
	t_tuple	roots = (t_tuple) {0.0, 0.0};
	int		count;

	count = quadratic_roots(a, b, c, &roots);
	bool	valid1 = true;
	bool	valid2 = true;
	t_vect3	Hp1 = ray_at(*ray, roots.x);
	t_vect3	Hp2 = ray_at(*ray, roots.y);
	double	Ho1 = vect3_dot(vect3_sub(cyl->capt, Hp1), cyl->axis);
	double	Ho2 = vect3_dot(vect3_sub(cyl->capt, Hp2), cyl->axis);
	int		valid_count = count;
	if (roots.x < 0.0 || Ho1 < EPS || Ho1 > cyl->h || !itv_surrounds(interval, roots.x))
	{
		valid1 = false;
		if (valid_count > 0)
			--valid_count;
	}
	if (roots.y < 0.0 || Ho2 < EPS || Ho2 > cyl->h || !itv_surrounds(interval, roots.y))
	{
		valid2 = false;
		if (valid_count > 0)
			--valid_count;
	}
	if (valid_count == 0)
	{
		if (ca_dot_rl <= 0.0)
			valid1 = rd_int(ray, &(cyl->capt), &(cyl->axis), cyl->r, &(roots.x));
		else if (ca_dot_rl >=cyl->h )
			valid1 = rd_int(ray, &(cyl->capb), &(cyl->axis), cyl->r, &(roots.x));
		else
		{
			valid1 = rd_int(ray, &(cyl->capt), &(cyl->axis), cyl->r, &(roots.x));
        	valid2 = rd_int(ray, &(cyl->capb), &(cyl->axis), cyl->r, &(roots.y));
			if (valid1)
			{
				if (valid2)
				{
					if (roots.y < roots.x)
						roots.x = roots.y;
				}
				if (itv_contains(interval, roots.x))
				{
					info->t = roots.x;
					return (true);
				}
				else
					return (false);
			}
			else if (valid2)
			{
				if (itv_contains(interval, roots.y))
				{
					info->t = roots.y;
					return (true);
				}
				else
					return (false);
			}
		}
		if (valid1 && itv_contains(interval, roots.x))
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
		bool	disc1 = rd_int(ray, &(cyl->capt), &(cyl->axis), cyl->r, &disc_near);
		bool	disc2 = rd_int(ray, &(cyl->capb), &(cyl->axis), cyl->r, &disc_away);
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

*/