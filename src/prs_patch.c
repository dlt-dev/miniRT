/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_patch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:39:06 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/29 14:39:15 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// TBD
// Returns -1 on errors, 0 otherwise.
int	prs_patch(t_prs *prs)
{
	if (prs->amb_count > 0)
		printf("AMBIENT LIGHT PATCH TBD\n");
	return (0);
}
