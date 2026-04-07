/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:10:01 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/07 13:17:49 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vector4.h"
# include "matrix.h"

// The Direction must be Normalized !
typedef struct s_ray
{
	t_pt	o;
	t_v4	dir;
}	t_ray;

// RAY FUNCTIONS
// returns the point at the given distance t along the ray r.
t_pt	ray_pos(const t_ray *ray, double t);

// Displays the ray
void	ray_prt(const t_ray *ray);

// Applies the transformation matrix m1 to the ray ray,
// stores the result in res.
// returns -1 on error, 0 otherwise.
int		ray_trf(const t_ray *ray, const t_m44 *m1, t_ray *res);	

#endif