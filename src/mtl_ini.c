/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtl_ini.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:50:11 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/22 11:06:28 by cybourge         ###   ########.fr       */
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
	m44_idm(&(mtl->pat.tm));
	m44_idm(&(mtl->pat.itm));
	mtl->pat.pat = NULL;
	ft_memset(&(mtl->tex), 0, sizeof(t_ftex));
}
