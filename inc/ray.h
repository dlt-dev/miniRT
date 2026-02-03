/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:05:13 by cybourge          #+#    #+#             */
/*   Updated: 2026/02/03 16:16:02 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vector3.h"
# include "color.h"

typedef struct s_ray
{
	t_point	o;
	t_vect3	dir;
}	t_ray;

t_vect3	ray_at(t_ray ray, double t);
t_color	ray_color(t_ray ray);

#endif