/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_trf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:11:44 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/21 11:02:39 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

// Takes the different transformations of the object and puts them into a
// single transformation matrix. Same for the inverse of these transformations.
// Composes the Affine decomposition :
// Transform = Translation * Rotation * Scaling * Shearing
// Transform_Inv = Shearing_Inv * Scaling_Inv * Rotation_Inv * Translation_Inv
// Transform_Inv_Transpose = Transpose(Transform_Inv)
int	obj_trf(t_obj *obj)
{
	t_m44	res1;
	t_m44	res2;

	if (!obj)
		return (-1);
	if (m44_prd(&(obj->trlm), &(obj->rotm), &res1) == -1)
		return (-1);
	if (m44_prd(&(obj->sclm), &(obj->shem), &res2) == -1)
		return (-1);
	if (m44_prd(&res1, &res2, &(obj->tm)) == -1)
		return (-1);
	if (m44_prd(&(obj->ishem), &(obj->isclm), &res1) == -1)
		return (-1);
	if (m44_prd(&(obj->irotm), &(obj->itrlm), &res2) == -1)
		return (-1);
	if (m44_prd(&res1, &res2, &(obj->itm)) == -1)
		return (-1);
	if (m44_trp(&(obj->itm), &(obj->itrpm)) == -1)
		return (-1);
	return (0);
}
