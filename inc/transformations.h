/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 08:18:17 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/01 11:05:49 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMATIONS_H
# define TRANSFORMATIONS_H

# include "matrix.h"
# include <string.h>

// Structure used to pass arguments to the shearing transformation matrix.
// xy means “x moved in proportion to y,” and represents the amount
// by which to multiply y before adding it to x
typedef struct s_shearing_param
{
	double	xy;
	double	xz;
	double	yx;
	double	yz;
	double	zx;
	double	zy;
}	t_spara;

// Writes the Translation Matrix corresponding
// to the translation by Vector v = (tx,ty,tz) in res.
// res will be shaped like :
// [ 1  0  0  tx ]
// [ 0  1  0  ty ]
// [ 0  0  1  tz ]
// [ 0  0  0   1 ]
int	m44_trl(double tx, double ty, double tz, t_m44 *res);

// Writes the Scaling Matrix corresponding to scaling along each axis by :
// (sx, sy, sz) where si = scaling factor along i axis in res.
// res will be shaped like :
// [ sx  0   0   0 ]
// [ 0   sy  0   0 ]
// [ 0   0   sz  0 ]
// [ 0   0   0   1 ]
int	m44_scl(double sx, double sy, double sz, t_m44 *res);

// Writes the Rotation Matrix that corresponds to a rotation of angle X along 
// the x axis. X is in radiants.
// res will be shaped like :
// [ 1     0        0     0 ]
// [ 0   cos(X)  -sin(X)  0 ]
// [ 0   sin(X)   cos(X)  0 ]
// [ 0     0        0     1 ]
int	m44_rotx(double x_angle, t_m44 *res);

// Writes the Rotation Matrix that corresponds to a rotation of angle Y along 
// the y axis. Y is in radiants.
// res will be shaped like :
// [  cos(Y)   0   sin(Y)   0 ]
// [    0      1     0      0 ]
// [ -sin(Y)   0   cos(Y)   0 ]
// [    0      0     0      1 ]
int	m44_roty(double y_angle, t_m44 *res);

// Writes the Rotation Matrix that corresponds to a rotation of angle Z along 
// the z axis. Z is in radiants.
// res will be shaped like :
// [ cos(Z)  -sin(Z)  0  0 ]
// [ sin(Z)   cos(Z)  0  0 ]
// [   0        0     1  0 ]
// [   0        0     0  1 ]
int	m44_rotz(double z_angle, t_m44 *res);

// Writes the Shearing Matrix defined by its parameters.
// res will be shaped like :
// [ 1   xy   xz   0 ]
// [ yx   1   yz   0 ]
// [ zx   zy   1   0 ]
// [ 0    0    0   1 ]
int	m44_she(t_spara param, t_m44 *res);
#endif