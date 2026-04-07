/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objv_prt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 09:04:14 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/07 09:08:09 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

void	objv_prt(const t_objv *objv)
{
	size_t	i;

	if (!objv)
		return ;
	printf("Objects (%zu) : [", objv->len);
	i = 0;
	while (i < objv->len)
	{
		obj_prt(&objv->v[i]);
		if (i + 1 < objv->len)
			printf(", ");
		i++;
	}
	printf("]\n");
}
