/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:39:09 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/26 09:33:45 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef V3_H
# define V3_H

# include <math.h>
# include <stdbool.h>
# define EPS 1e-9

typedef struct s_v3
{
	double	x;
	double	y;
	double	z;
}			t_v3;

typedef t_v3	t_point;

bool		deql(double a, double b);	// Equality for 2 double.

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
