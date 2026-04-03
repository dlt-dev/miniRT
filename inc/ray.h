/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:10:01 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/03 12:11:12 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vector4.h"

// The Direction must be Normalized !
typedef struct s_ray
{
	t_pt	o;
	t_v4	dir;
}	t_ray;

// RAY FUNCTIONS
// returns the point at the given distance t along the ray r.
t_pt		ray_pos(const t_ray *ray, double t);

#endif