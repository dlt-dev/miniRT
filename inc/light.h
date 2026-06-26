/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 09:21:50 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/26 09:39:53 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "vector4.h"
# include "color.h"
# include <stdlib.h>
# include <stdio.h>

// Defines a Point Light
// clr : Intensity / color of the light
// pos : Position of the light
typedef struct s_light
{
	t_clr	clr;		
	t_pt	pos;
}	t_lgt;

// Variable size array structure (vector) that holds lights
// len	: number of objects stored.
// cap	: total capacity of the Array.
// v	: the actual vector.
typedef struct s_lightv
{
	size_t	len;
	size_t	cap;
	t_lgt	*v;
}	t_lgtv;

// Sets the fields of the light to the given arguments.
void	lgt_set(t_lgt *light, t_pt pos, uint32_t clr);

// Creates an empty light vector with a capacity of cap.
// If the allocation is unsucessfull :
//	- cap = 0.
//	- v = NULL.
t_lgtv	lgtv_crt(size_t cap);

// Frees the lgtv and sets all its field to 0.
void	lgtv_dlt(t_lgtv	*lgtv);

// Clears the light vector's element by setting its len to 0.
void	lgtv_clr(t_lgtv *lgtv);

// Adds an object to the light vector.
// Reallocates twice its capacity if needed.
// return -1 on error, 0 on success.
int		lgtv_add(t_lgtv *lgtv, const t_lgt *light);

// Displays the light vector
void	lgtv_prt(const t_lgtv *lgtv);

#endif