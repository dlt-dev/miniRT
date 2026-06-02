/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trf_trf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:11:44 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/02 10:51:01 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformations.h"

// Takes the different transformations of the trfect and puts them into a
// single transformation matrix. Same for the inverse of these transformations.
// Composes the Affine decomposition :
// Transform = Translation * Rotation * Scaling * Shearing
// Transform_Inv = Shearing_Inv * Scaling_Inv * Rotation_Inv * Translation_Inv
// Transform_Inv_Transpose = Transpose(Transform_Inv)
int	trf_trf(t_trf *trf)
{
	t_m44	res1;
	t_m44	res2;

	if (!trf)
		return (-1);
	if (m44_prd(&(trf->trlm), &(trf->rotm), &res1) == -1)
		return (-1);
	if (m44_prd(&(trf->sclm), &(trf->shem), &res2) == -1)
		return (-1);
	if (m44_prd(&res1, &res2, &(trf->tm)) == -1)
		return (-1);
	if (m44_prd(&(trf->ishem), &(trf->isclm), &res1) == -1)
		return (-1);
	if (m44_prd(&(trf->irotm), &(trf->itrlm), &res2) == -1)
		return (-1);
	if (m44_prd(&res1, &res2, &(trf->itm)) == -1)
		return (-1);
	if (m44_trp(&(trf->itm), &(trf->itmt)) == -1)
		return (-1);
	return (0);
}
