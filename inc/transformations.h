/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 08:18:17 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/02 11:30:55 by cybourge         ###   ########.fr       */
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

// Structure used to hold the data needed to create, edit and apply
// a transformation.
// tm	: transformation matrix.
// itm	: inverse transformation matrix.
// itmt	: inverse  transformation matrix transpose.
// trlm	: translation matrix.
// sclm	: scaling matrix.
// rotm	: rotation matrix.
// shem	: shearing matrix.
// itrlm: inverse translation matrix.
// isclm: inverse scaling matrix.
// irotm: inverse rotation matrix.
// ishem: inverse shearing matrix.
typedef struct s_transformation_set
{
	t_m44		tm;
	t_m44		itm;
	t_m44		itmt;
	t_m44		trlm;
	t_m44		sclm;
	t_m44		rotm;
	t_m44		shem;
	t_m44		itrlm;
	t_m44		isclm;
	t_m44		irotm;
	t_m44		ishem;
}	t_trf;

// Sets all the matrices to the Identity matrice.
void	trf_ini(t_trf *trf);

// Applies a translation by updating trf's 
// translation and inverse translation matrices.
// returns -1 on error, 0 otherwise.
int		trf_trl(t_trf *trf, double tx, double ty, double tz);
// Applies a scaling transformation by updating trf's 
// scaling and inverse scaling matrices.
// Returns -1 on error, 0 otherwise.
int		trf_scl(t_trf *trf, double sx, double sy, double sz);
// Applies a rotation transformation by updating trf's 
// rotation and inverse rotation matrices.
// Returns -1 on error, 0 otherwise.
int		trf_rot(t_trf *trf, double rx, double ry, double rz);
// Applies a shearing transformation by updating trf's
// shearing and inverse shearing matrices.
// Returns -1 on error, 0 otherwise.
int		trf_she(t_trf *trf, t_spara param);
// Applies all the stored transformations by updating trf's
// transformation, inverse transformation and inverse transformation transpose
// matrices.
// Returns -1 on error, 0 otherwise.
int		trf_trf(t_trf *trf);

// Writes the Translation Matrix corresponding
// to the translation by Vector v = (tx,ty,tz) in res.
// res will be shaped like :
// [ 1  0  0  tx ]
// [ 0  1  0  ty ]
// [ 0  0  1  tz ]
// [ 0  0  0   1 ]
int		m44_trl(double tx, double ty, double tz, t_m44 *res);

// Writes the Scaling Matrix corresponding to scaling along each axis by :
// (sx, sy, sz) where si = scaling factor along i axis in res.
// res will be shaped like :
// [ sx  0   0   0 ]
// [ 0   sy  0   0 ]
// [ 0   0   sz  0 ]
// [ 0   0   0   1 ]
int		m44_scl(double sx, double sy, double sz, t_m44 *res);

// Writes the Rotation Matrix that corresponds to a rotation of angle X along 
// the x axis. X is in radiants.
// res will be shaped like :
// [ 1     0        0     0 ]
// [ 0   cos(X)  -sin(X)  0 ]
// [ 0   sin(X)   cos(X)  0 ]
// [ 0     0        0     1 ]
int		m44_rotx(double x_angle, t_m44 *res);

// Writes the Rotation Matrix that corresponds to a rotation of angle Y along 
// the y axis. Y is in radiants.
// res will be shaped like :
// [  cos(Y)   0   sin(Y)   0 ]
// [    0      1     0      0 ]
// [ -sin(Y)   0   cos(Y)   0 ]
// [    0      0     0      1 ]
int		m44_roty(double y_angle, t_m44 *res);

// Writes the Rotation Matrix that corresponds to a rotation of angle Z along 
// the z axis. Z is in radiants.
// res will be shaped like :
// [ cos(Z)  -sin(Z)  0  0 ]
// [ sin(Z)   cos(Z)  0  0 ]
// [   0        0     1  0 ]
// [   0        0     0  1 ]
int		m44_rotz(double z_angle, t_m44 *res);

// Writes the Shearing Matrix defined by its parameters.
// res will be shaped like :
// [ 1   xy   xz   0 ]
// [ yx   1   yz   0 ]
// [ zx   zy   1   0 ]
// [ 0    0    0   1 ]
int		m44_she(t_spara param, t_m44 *res);
#endif