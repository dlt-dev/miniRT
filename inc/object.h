/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:11:44 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/03 14:38:14 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "ray.h"
# include "utils.h"
# include "color.h"
# include "vector4.h"
# include "intersection.h"
# include <stdlib.h>

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
	t_clr	clr;
}	t_sph;

typedef struct s_object
{
	t_oty		type;
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



// OBJECT FUNCTIONS
// returns an instance of sphere
t_sph		sph_crt(void);
// returns wether a ray hits a sphere object and adds the intersection to itxv.
bool		sph_hit(const t_obj *obj, const t_ray *r, t_itxv *itxv);

#endif