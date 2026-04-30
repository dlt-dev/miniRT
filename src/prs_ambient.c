/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:17:52 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/30 11:57:58 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Parse Ambient lights.
// prs : parser strcture that hold the scene.
// ltab : line in a string table format that holds the data to be parsed.
// Returns -1 on error, 0 otherwise. 
int	prs_ambient(t_prs *prs, char **ltab)
{
	const t_itv		bounds = {.max = 1.0, .min = 0.0};
	const size_t	len = tab_len(ltab);

	if (prs->amb_count > 0)
		return (ft_err_prt("Too many ambient lights defined\n", -1));
	if (len < 3)
		return (ft_err_prt("Incomplete Ambient Light data\n", -1));
	else if (len > 3)
		return (ft_err_prt("Too much data given for Ambient Light\n", -1));
	if (!is_validf(ltab[1]))
		return (ft_err_prt("Invalid Ambient Light intensity\n", -1));
	prs->scn->world.amb.intensity = ft_atof(ltab[1]);
	if (!itv_cnt(bounds, prs->scn->world.amb.intensity))
		return (ft_err_prt(
				"Ambient Light intensity must be between [0.0, 1.0]\n", -1));
	if (prs_clr(ltab[2], &(prs->scn->world.amb.clr)) == -1)
		return (-1);
	prs->scn->world.amb.clr = clr_mul(prs->scn->world.amb.clr,
			prs->scn->world.amb.intensity);
	prs->amb_count++;
	return (0);
}
