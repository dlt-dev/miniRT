/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:19:17 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/30 11:38:46 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Parses the light line.
// prs : parser structure that holds the scene.
// ltab : line in a string table that holds the data to be parsed.
// Returns -1 on errors, 0 otherwise.
int	prs_light(t_prs *prs, char **ltab)
{
	t_lgt		lgt;
	double		intensity;
	const t_itv	int_bounds = itv_crt(0.0, 1.0);

	if (tab_len(ltab) != 4)
		return (ft_err_prt("Invalid Light Data\n", -1));
	if (prs_v3(ltab[1], &(lgt.pos), false) == -1)
		return (ft_err_prt("Invalid Light Position\n", -1));
	if (!is_validf(ltab[2]))
		return (ft_err_prt("Invalid Light Brightness\n", -1));
	intensity = ft_atof(ltab[2]);
	if (!itv_cnt(int_bounds, intensity))
		return (ft_err_prt("Invalid Light Brightness\n", -1));
	if (prs_clr(ltab[3], &(lgt.clr)) == -1)
		return (ft_err_prt("Invalid Light color\n", -1));
	lgt.clr = clr_mul(lgt.clr, intensity);
	if (lgtv_add(&(prs->scn->world.lgts), &lgt) == -1)
		return (-1);
	return (0);
}
