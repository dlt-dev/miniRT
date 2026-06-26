/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_prt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 09:03:32 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/26 09:47:28 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

void	obj_prt(const t_obj *obj)
{
	if (!obj)
		return ;
	printf("%s\n", oty_prt(obj->type));
	mtl_prt(&(obj->mtrl));
	m44_prt(&(obj->tm));
	m44_prt(&(obj->itm));
}
