/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:14:14 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 11:32:47 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include <stdlib.h>
# include "utils.h"
# include "vector4.h"
# include "ray.h"
# include <stdio.h>

typedef struct s_object t_obj;

// Structure that holds the data resulting from an object hit.
// obj : The object that was hit.
// t : the parameter along the ray for which the object is hit.
// hp : Hit Point in World Space
// rd : the ray's direction vector from which the hit resulted.
// nrm : normal vector to the surface at the hitpoint.
typedef struct s_intersection
{
	const t_obj	*obj;
	double		t;
	t_pt		hp;
	t_v4		rd;
	t_v4		nrm;
}	t_itx;

// Vector structure that holds intersections
// len	: holds the number of elements stored.
// cap	: holds the total capacity of the vector.
// v	: the actual vector.
typedef struct s_intersection_vector
{
	size_t	len;
	size_t	cap;
	t_itx	*v;
}	t_itxv;

// Initialises the hit information of the itx, 
// the obj and t fields must have been set before calling this function.
// returns -1 on error, 0 otherwise.
int		itx_ini(t_itx *itx, const t_ray *ray);

// Displays the intersection and its fields.
void	itx_prt(const t_itx *itx);

// Creates an empty intersection vector with a capacity of cap.
// If the allocation is unsucessfull :
// 	- cap = 0;
//	- v = NULL;
t_itxv	itxv_crt(size_t cap);

// Frees the itxv and sets all of its fields to 0;
void	itxv_dlt(t_itxv *itxv);

// Clears the itxv of its elements.
void	itxv_clr(t_itxv *itxv);

// Adds an intersection to the intersection vector.
// If there isn't enough capacity,
// reallocates the vector with twice the capacity and adds the intersection.
// returns -1 on error, 0 on success.
int		itxv_add(t_itxv *itxv, const t_itx *itx);

// Sorts an intersection vector using quicksort in ascending order.
void	itxv_sort(const t_itxv *itxv);

// Returns the smallest non negative itx inside the itxv.
// itxv is assumed to be sorted in ascending order.
t_itx	itxv_hit(const t_itxv *itxv);

// Prints the intersection vector.
void	itxv_prt(const t_itxv *itxv);

#endif
