/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objl_dlt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 09:40:34 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/05 10:17:04 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

void	objl_dlt(t_objl **objl, const t_obj *to_delete)
{
	t_objl	*cur;
	t_objl	*prev;

	if (objl == NULL || *objl == NULL || to_delete == NULL)
		return ;
	cur = *objl;
	prev = NULL;
	while (cur != NULL)
	{
		if (cur->obj == to_delete)
		{
			if (prev == NULL)
				*objl = cur->next;
			else
				prev->next = cur->next;
			free(cur);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}
