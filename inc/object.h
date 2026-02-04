/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:46:28 by cybourge          #+#    #+#             */
/*   Updated: 2026/02/04 14:58:23 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H
# include "color.h"
# include "vector3.h"

typedef struct s_ray	t_ray;

typedef struct s_hitinfo
{
	t_point				p;
	t_vect3				n;
	double				t;
}						t_hitinfo;

typedef struct s_itv
{
	bool				min_included;
	double				min;
	bool				max_included;
	double				max;
}						t_itv;

typedef struct s_sphere
{
	t_point				c;
	double				r;
	t_color				color;
	// bool	(*is_hit)(t_sphere *, t_ray *, t_hitinfo *);
}						t_sphere;

bool					itv_isin(t_itv *interval, double value);

double					sphere_is_hit(t_sphere *sphere, t_ray *ray);
bool					sphere_is_hit_test(t_sphere *sphere, t_ray *ray);
bool					sphere_hit(t_sphere *sphere, t_ray *ray,
							t_hitinfo *info);

#endif