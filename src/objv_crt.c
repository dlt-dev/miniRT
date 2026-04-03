/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objv_crt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 14:37:40 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/03 14:38:22 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_objv	objv_crt(size_t cap)
{
	t_objv	objv;

	objv.len = 0;
	objv.cap = cap;
	if (cap == 0)
	{
		objv.v = NULL;
		return (objv);
	}
	objv.v = malloc(sizeof(t_obj) * cap);
	if (!objv.v)
	{
		objv.cap = 0;
		return (objv);
	}
	return (objv);
}
