/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:39:09 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 10:37:02 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR4_H
# define VECTOR4_H

# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include "utils.h"

// x,y,z are the 3 coordinates of the vector in 3D space.
// w is a binary value that represents if the vector is a point or not :
// 1 -> is a point, 0 -> is a vector.
typedef struct s_vector4
{
	double	x;
	double	y;
	double	z;
	double	w;
}			t_v4;

typedef t_v4	t_pt;	// Used to represent points in 3D space.

// Creates a Point, automatically setting w to 1.0.
t_pt		pt_crt(double x, double y, double z);
// Creates a Vector3, automatically setting w to 0.0.
t_v4		v4_crt(double x, double y, double z);
// Prints the vector in column form.
void		v4_prt(const t_v4 *v);
// Prints the vector in line form.
void		v4_lprt(const t_v4 *v);
// Prints the vectors in column form : v1 (operation) v2 = v3
void		v4_prt_bop(
				const t_v4 *v1,
				const t_v4 *v2,
				const t_v4 *v3,
				const char *op
				);
// Prints the vectors in column form : (operation) v1 = v2
void		v4_prt_uop(const t_v4 *v1, const t_v4 *v2, const char *op);

// COMPARISON
bool		v4_eql(t_v4 a, t_v4 b);		// Equality for 2 vectors.
// BASIC OPERATIONS
t_v4		v4_add(t_v4 a, t_v4 b);
t_v4		v4_sub(t_v4 a, t_v4 b);
t_v4		v4_inv(t_v4 v);				// Inverse of v.
// LENGTH OPERATIONS
double		v4_lsq(t_v4 v);				// Length squared.
double		v4_len(t_v4 v);				// Length.
t_v4		v4_uni(t_v4 v);				// Unit vector based on v.
// PRODUCTS
double		v4_dot(t_v4 a, t_v4 b);		// Dot product.
t_v4		v4_xpr(t_v4 a, t_v4 b);		// Cross product.
// SCALAR OPERATIONS
t_v4		v4_mul(t_v4 v, double s);	// Scalar multiplication.
t_v4		v4_div(t_v4 v, double s);	// Scalar division.

// GEOMETRIC FUNCTIONS
t_v4		v4_rfl(const t_v4 *in, const t_v4 *nrml); // Reflect in by nmrl.

#endif
