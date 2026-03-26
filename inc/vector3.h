/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:39:09 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/26 08:18:30 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

# include <math.h>
# include <stdbool.h>
# define EPS 1e-9

typedef struct s_vect3
{
	double	x;
	double	y;
	double	z;
}			t_vect3;

typedef t_vect3	t_point;

bool		vect3_equal(t_vect3 a, t_vect3 b);
bool		double_equal(double a, double b);

/* Basic operations */
t_vect3		vect3_add(t_vect3 a, t_vect3 b);
t_vect3		vect3_sub(t_vect3 a, t_vect3 b);
t_vect3		vect3_inv(t_vect3 v);

/* Length and normalization */
double		vect3_length_squared(t_vect3 v);
double		vect3_norm(t_vect3 v);
t_vect3		vect3_unit(t_vect3 v);

/* Products */
double		vect3_dot(t_vect3 a, t_vect3 b);
t_vect3		vect3_cross(t_vect3 a, t_vect3 b);

/* Scalar operations */
t_vect3		vect3_mul_scalar(t_vect3 v, double s);
t_vect3		vect3_div_scalar(t_vect3 v, double s);

#endif /* VECT3_H */
