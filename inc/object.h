/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:11:44 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 17:30:56 by cybourge         ###   ########.fr       */
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
# include "light.h"
# include "material.h"
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

// Used to store the variables used when computing the lightning of an object.
// ldn : lightv dot normal
// rdrd : light reflect for raydir
typedef struct s_object_lighting
{
	t_clr	eff_clr;
	t_clr	ambient;
	t_clr	diffuse;
	t_clr	specular;
	t_v4	lightv;
	t_v4	nlightv;
	t_v4	reflectv;
	double	ldn;
	double	rdrd;
}	t_obj_lgt;

typedef enum e_obj_type
{
	DEFAULT = 0,
	SPHERE,
	PLANE,
	CYLINDER,
	CONE
}	t_oty;

typedef struct s_plane
{
	t_v4	nrml;
}	t_pln;

typedef struct s_cylinder
{
	bool	closed;
	double	min;
	double	max;
}	t_cld;

typedef struct s_sphere
{
	t_pt	c;
	double	r;
}	t_sph;

typedef struct s_cone
{
	bool	closed;
	double	min;
	double	max;
}	t_con;

// ittm : Inverse transpose tranformation matrix.
// gcord : Function to get coordinates in a specific referetial.
typedef struct s_object
{
	t_oty		type;
	t_m44		tm;
	t_m44		itm;
	t_m44		itmt;
	t_mtl		mtrl;
	bool		(*hit)(const t_obj *, const t_ray *, t_itxv *);
	int			(*nrml)(const t_obj *, const t_pt *, t_v4 *);
	t_pt		(*gcord)(const t_pt *);
	union
	{
		t_sph	sp;
		t_pln	pl;
		t_cld	cy;
		t_con	co;
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

// Linked list structure that hold pointers to existing objects.
typedef struct s_object_list
{
	const t_obj				*obj;
	struct s_object_list	*next;
}	t_objl;

// Adds new_obj at the end of the objl
// Returns -1 on error, 0 otherwise.
int			objl_add(t_objl **objl, const t_obj *new_obj);

// Removes the first occurence of to_delete from objl
void		objl_dlt(t_objl **objl, const t_obj *to_delete);

// Returns true if to_find is in objl
bool		objl_isin(const t_objl *objl, const t_obj *to_find);

// Returns the last obj in objl, NULL is objl is empty.
const t_obj	*objl_last(const t_objl *objl);

// Frees each node of the objl
void		objl_free(t_objl *objl);

// Creates an empty object vector with a capacity of cap.
// If the allocation is unsucessfull :
//	- cap = 0.
//	- v = NULL.
t_objv		objv_crt(size_t cap);

// Frees the objv and sets all its field to 0.
void		objv_dlt(t_objv	*objv);

// Adds an object to the object vector.
// Reallocates twice its capacity if needed.
// return -1 on error, 0 on success.
int			objv_add(t_objv *objv, const t_obj *obj);

// Returns the string literal corresponding the the object type.
const char	*oty_prt(t_oty	type);
// Prints an object.
void		obj_prt(const t_obj *obj);
// Prints the Object Vector.
void		objv_prt(const t_objv *objv);

// OBJECT FUNCTIONS

// Frees any memory allocated in the object.
void		obj_dlt(t_obj *obj);

// Applies all the transformations to the object.
// Returns -1 on error, 0 otherwise.
int			obj_trf(t_obj *obj, t_trf const *trf);

// Lights an object.
// Returns the color.
t_clr		obj_lgt(
				const t_obj *obj,
				const t_lgt *light,
				const t_itx *data,
				bool shadowed);
// Returns an instance of a sphere obj with default values.
t_obj		sph_crt(void);
// Returns wether a ray hits a sphere object and adds the intersection to itxv.
bool		sph_hit(const t_obj *obj, const t_ray *r, t_itxv *itxv);
// Writes the normalized normal vector to a sphere "obj"
// at point "pt" into "nrml".
// Returns -1 on error, 0 otherwize.
int			sph_nrml(const t_obj *obj, const t_pt *pt, t_v4 *nrml);
// Returns the (u,v) coordinates of a point on a unit sphere.
t_pt		sph_cord(const t_pt *point);

// Returns an instance of a plane obj with default values.
t_obj		pln_crt(void);
// Returns wether a ray hits a plane object and adds the intersection to itxv.
bool		pln_hit(const t_obj *obj, const t_ray *r, t_itxv *itxv);
// Writes the normal vector of the plane object into nrml.
// Returns -1 on errors, 0 otherwise.
int			pln_nrml(const t_obj *obj, const t_pt *pt, t_v4 *nrml);
// Returs the (u,v) cordinates of a point on a plane.
t_pt		pln_cord(const t_pt *point);

// Returns an instance of a cylinder with default values.
t_obj		cld_crt(void);
// Returns wether a ray hits a cylinder object,
// adds the intersection to itxv.
bool		cld_hit(const t_obj *obj, const t_ray *r, t_itxv *itxv);
// Writes the normalized normal vector to the cylinder at point pt in nrml.
// Returns -1 on errors, 0 otherwise.
int			cld_nrml(const t_obj *obj, const t_pt *pt, t_v4 *nrml);
// Returns the coordinates of P in cylindrical form.
t_pt		cld_cord(const t_pt *point);

// Returns an instance of a cone with default values.
t_obj		con_crt(void);
// Returns wether a ray hits a cone object and adds the intersection to itxv.
bool		con_hit(const t_obj *obj, const t_ray *r, t_itxv *itxv);
// Writes the normaliwed normal vector to the cone at point pt in nrml.
// Returns -1 on errors, 0 otherwise.
int			con_nrml(const t_obj *obj, const t_pt *pt, t_v4 *nrml);
// Returns the UV coordinates of the point P on a cone.
t_pt		con_cord(const t_pt *point);

// Returns the color of an object at a specific point.
t_clr		obj_gclr(const t_obj *obj, const t_pt *p);

#endif