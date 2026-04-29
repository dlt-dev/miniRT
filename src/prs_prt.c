/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_prt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:36:45 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/29 14:36:50 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	prs_prt(const t_prs *prs)
{
	printf("Filename : %s\n", prs->fname);
	objv_prt(&(prs->scn->world.objs));
	lgtv_prt(&(prs->scn->world.lgts));
	cam_prt(&(prs->scn->camera));
}
