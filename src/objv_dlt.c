/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objv_dlt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 14:39:22 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/03 14:48:18 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

void	objv_dlt(t_objv *objv)
{
	if (!objv)
		return ;
	if (objv->v)
		free(objv->v);
	objv->v = NULL;
	objv->len = 0;
	objv->cap = 0;
}
