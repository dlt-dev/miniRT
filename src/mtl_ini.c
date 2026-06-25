/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtl_ini.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:50:11 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 15:33:56 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

void	mtl_ini(t_mtl *mtl)
{
	mtl->clr = clr_unpack(RED);
	mtl->amb = 0.1;
	mtl->dif = 0.9;
	mtl->spc = 0.9;
	mtl->shi = 200;
	mtl->rfl = 0.0;
	mtl->ref = 1.0;
	mtl->tsp = 0.0;
	m44_idm(&(mtl->tm));
	m44_idm(&(mtl->itm));
	mtl->tex = NULL;
	mtl->hmap = NULL;
}
