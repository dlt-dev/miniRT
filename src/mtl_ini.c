/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtl_ini.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:50:11 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/02 11:53:17 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

void	mtl_ini(t_mtl *mtl)
{
	mtl->clr = clr_unpack(RED);
	mtl->amb = 0.5;
	mtl->dif = 0.8;
	mtl->spc = 0.5;
	mtl->shi = 100.0;
	m44_idm(&(mtl->pat.tm));
	m44_idm(&(mtl->pat.itm));
	mtl->pat.pat = NULL;
}
