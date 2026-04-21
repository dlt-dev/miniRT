/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:11:44 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/21 15:03:13 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "ray.h"
# include "utils.h"
# include "color.h"
# include "vector4.h"
# include "matrix.h"
# include "transformations.h"
# include "intersection.h"
# include <stdlib.h>
# include <stdio.h>

// Used to store the data relating to a second degree polynomial.
typedef struct s_polynome_2
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	r1;
	double	r2;
}	t_pol2;

typedef	struct s_material
{
	t_clr	clr;
	double	amb;
	double	dif;
	double	spc;
	double	shi;
}	t_mtl;


typedef enum e_obj_type
{
	DEFAULT = 0,
	SPHERE,
	PLANE,
	CYLINDER
}	t_oty;

typedef struct s_plane
{
}	t_pln;

typedef struct s_cylinder
{
}	t_cld;

typedef struct s_sphere
{
	t_pt	c;
	double	r;
}	t_sph;


typedef struct s_object
{
	t_oty		type;
	t_m44		tm;
	t_m44		itm;
	t_m44		ittm;
	t_m44		trlm;
	t_m44		sclm;
	t_m44		rotm;
	t_m44		shem;
	t_m44		itrlm;
	t_m44		isclm;
	t_m44		irotm;
	t_m44		ishem;
	t_mtl		mtrl;
	union
	{
		t_sph	sp;
		t_pln	pl;
		t_cld	cy;
	}	u_o;
}	t_obj;

// Variable size array structure (vector) that holds geometric objects
// len	: number of objects stored.
// cap	: total capacity of the Array.
// v	: the actual vector.
typedef struct s_object_vector
{
	size_t	len;
	size_t	cap;
	t_obj	*v;
}	t_objv;

// Defines a Point Light
// clr : Intensity / color of the light
// pos : Position of the light
typedef struct s_light
{
	t_clr	clr;		
	t_pt	pos;
}	t_lgt;

// Structure that holds the data resulting from an object hit.
// hp : Hit Point in World Space
// rd : the ray's direction vector from which the hit resulted.
// nrm : normal vector to the surface at the hitpoint.
typedef struct t_hit
{
	t_pt	hp;
	t_v4	rd;
	t_v4	nrm;
}	t_hit;

// Creates an empty object vector with a capacity of cap.
// If the allocation is unsecessfull :
//	- cap = 0.
//	- v = NULL.
t_objv	objv_crt(size_t cap);

// Frees the objv and sets all its field to 0.
void	objv_dlt(t_objv	*objv);

// Adds an object to the object vector.
// Reallocates twice its capacity if needed.
// return -1 on error, 0 on success.
int		objv_add(t_objv *objv, const t_obj *obj);

// Returns the string literal corresponding the the object type.
const char	*oty_prt(t_oty	type);
// Prints an object.
void		obj_prt(const t_obj *obj);
// Prints the Object Vector.
void		objv_prt(const t_objv *objv);

// OBJECT FUNCTIONS

// Applies a translation by updating obj's matrixes.
// returns -1 on error, 0 otherwise.
int			obj_trl(t_obj *obj, double tx, double ty, double tz);
// Applies a scaling transformation by updating obj's matrixes.
// Returns -1 on error, 0 otherwise.
int			obj_scl(t_obj *obj, double sx, double sy, double sz);
// Applies a rotation transformation by updating obj's matrixes.
// Returns -1 on error, 0 otherwise.
int			obj_rot(t_obj *obj, double rx, double ry, double rz);
// Applies a shearing transformation by updating obj's matrixes.
// Returns -1 on error, 0 otherwise.
int			obj_she(t_obj *obj, t_spara param);
// Applies all the stored transformations to the object.
// Returns -1 on error, 0 otherwise.
int			obj_trf(t_obj *obj);

// Lights an object.
// Returns the color.
t_clr		obj_lgt(const t_obj *obj, const t_lgt *light, const t_hit *data);
// Returns an instance of a sphere obj
t_obj		sph_crt(void);
// Returns wether a ray hits a sphere object and adds the intersection to itxv.
bool		sph_hit(const t_obj *obj, const t_ray *r, t_itxv *itxv);
// Writes the normalized normal vector to a sphere "obj" at point "pt" into "nrml".
// Returns -1 on error, 0 otherwize.
int			sph_nrml(const t_obj *obj, const t_pt *pt, t_v4 *nrml);

#endif