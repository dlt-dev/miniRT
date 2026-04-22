/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wld_add_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:54:05 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/22 13:58:58 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

int	wld_add_obj(t_wld *wld, const t_obj *obj)
{
	if (!wld || !obj)
		return (-1);
	objv_add(&(wld->objs), obj);
	return (0);
}
