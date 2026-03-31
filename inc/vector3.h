/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:39:09 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/31 09:29:55 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

# include <math.h>
# include <stdbool.h>
# include "utils.h"


// x,y,z are the 3 coordinates of the vector.
// w is a binary value that represents if the vector is a point or not :
// 1 -> is a point, 0 -> is a vector.
typedef struct s_vector3
{
	double	x;
	double	y;
	double	z;
	double	w;
}			t_v3;

typedef t_v3	t_pt;	// Used to represent points in 3D space.

// Creates a Point, automatically setting w to 1.0.
t_pt		pt_crt(double x, double y, double z);
// Creates a Vector3, automatically setting w to 0.0.
t_v3		v3_crt(double x, double y, double z);

// COMPARISON
bool		v3_eql(t_v3 a, t_v3 b);		// Equality for 2 vectors.
// BASIC OPERATIONS
t_v3		v3_add(t_v3 a, t_v3 b);
t_v3		v3_sub(t_v3 a, t_v3 b);
t_v3		v3_inv(t_v3 v);				// Inverse of v.
// LENGTH OPERATIONS
double		v3_lsq(t_v3 v);				// Length squared.
double		v3_len(t_v3 v);				// Length.
t_v3		v3_uni(t_v3 v);				// Unit vector based on v.
// PRODUCTS
double		v3_dot(t_v3 a, t_v3 b);		// Dot product.
t_v3		v3_xpr(t_v3 a, t_v3 b);		// Cross product.
// SCALAR OPERATIONS
t_v3		v3_mul(t_v3 v, double s);	// Scalar multiplication.
t_v3		v3_div(t_v3 v, double s);	// Scalar division.

#endif
