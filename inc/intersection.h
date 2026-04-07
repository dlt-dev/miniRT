/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:14:14 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/07 09:48:12 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include <stdlib.h>
# include "utils.h"
# include <stdio.h>

typedef struct s_object t_obj;

typedef struct s_intersection
{
	const t_obj	*obj;
	double	t;
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

// Creates an empty intersection vector with a capacity of cap.
// If the allocation is unsucessfull :
// 	- cap = 0;
//	- v = NULL;
t_itxv	itxv_crt(size_t cap);

// Frees the itxv and sets all of its fields to 0;
void	itxv_dlt(t_itxv *itxv);

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
