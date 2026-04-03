/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objv_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 14:40:46 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/03 14:48:24 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

int	objv_add(t_objv *objv, const t_obj *obj)
{
	t_obj	*new_v;
	size_t	new_cap;

	if (!objv || !obj)
		return (-1);
	if (objv->len >= objv->cap)
	{
		if (objv->cap == 0)
			new_cap = 1;
		else
			new_cap = objv->cap * 2;
		new_v = malloc(sizeof(t_obj) * new_cap);
		if (!new_v)
			return (-1);
		ft_memcpy(new_v, objv->v, sizeof(t_obj) * objv->cap);
		free(objv->v);
		objv->v = new_v;
		objv->cap = new_cap;
	}
	objv->v[objv->len] = *obj;
	objv->len++;
	return (0);
}
