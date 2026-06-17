/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_clr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:16:15 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/17 11:20:04 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Assumes tab is a valid color array.
// writes the fields of tab into clr : maps [0,255] -> [0.0, 1.0].
static void	clr_write(t_clr *clr, char **tab)
{
	clr->r = ft_atoi(tab[0]) / 255.0;
	clr->g = ft_atoi(tab[1]) / 255.0;
	clr->b = ft_atoi(tab[2]) / 255.0;
	clr->t = 0.0;
}

// Parses a color given by input and writes the results in clr.
// Returns -1 on error, 0 otherwise.
int	prs_clr(const char *input, t_clr *clr)
{
	char		**clr_tab;

	clr_tab = ft_split(input, ",");
	if (!clr_tab)
		return (-1);
	if (tab_len(clr_tab) < 3)
	{
		tab_dlt(clr_tab);
		return (ft_err_prt("Not enough color fields given\n", -1));
	}
	if (tab_len(clr_tab) > 3)
	{
		tab_dlt(clr_tab);
		return (ft_err_prt("Too many color fields given\n", -1));
	}
	if (!is_validclr(clr_tab))
	{
		tab_dlt(clr_tab);
		return (ft_err_prt("Invalid color fields\n", -1));
	}
	clr_write(clr, clr_tab);
	tab_dlt(clr_tab);
	return (0);
}
