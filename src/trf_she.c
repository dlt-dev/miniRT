/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trf_she.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 09:23:35 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/02 10:50:30 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformations.h"

int	trf_she(t_trf *trf, t_spara param)
{
	t_m44	she_mat;
	t_m44	ishe_mat;
	t_m44	res_mat;

	if (m44_she(param, &she_mat) == -1)
		return (-1);
	if (m44_inv_she(&she_mat, &ishe_mat) == -1)
		return (-1);
	if (m44_prd(&she_mat, &(trf->shem), &res_mat) == -1)
		return (-1);
	if (m44_cpy(&res_mat, &(trf->shem)) == -1)
		return (-1);
	if (m44_prd(&(trf->ishem), &ishe_mat, &res_mat) == -1)
		return (-1);
	if (m44_cpy(&res_mat, &(trf->ishem)) == -1)
		return (-1);
	return (0);
}
