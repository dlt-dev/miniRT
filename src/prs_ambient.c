/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:17:52 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/29 14:45:24 by cybourge         ###   ########.fr       */
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
	{
		printf("Too many ambient lights defined\n");
		return (-1);
	}
	if (len < 3)
	{
		printf("Incomplete Ambient Light data\n");
		return (-1);
	}
	else if (len > 3)
	{
		printf("Too much data given for Ambient Light\n");
		return (-1);
	}
	if (!is_validf(ltab[1]))
	{
		printf("Invalid Ambient Light intensity\n");
		return (-1);
	}
	prs->ambl.intensity = ft_atof(ltab[1]);
	if (!itv_cnt(bounds, prs->ambl.intensity))
	{
		printf("Ambient Light intensity must be between [0.0, 1.0]\n");
		return (-1);
	}
	if (prs_clr(ltab[2], &(prs->ambl.clr)) == -1)
		return (-1);
	prs->amb_count++;
	return (0);
}
