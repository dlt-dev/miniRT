/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_cmplt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:38:16 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/30 11:39:15 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Checks if the scenes minimal parameters have been properly set :
// - at least a camera.
// Returns -1 one error, 0 otherwise.
int	prs_cmplt(t_prs *prs)
{
	if (prs->cam_count <= 0)
		return (ft_err_prt("At least one Camera is required\n", -1));
	return (0);
}
