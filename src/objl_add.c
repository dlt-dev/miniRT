/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objl_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 09:40:07 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/05 10:17:29 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

int	objl_add(t_objl **objl, const t_obj *new_obj)
{
	t_objl	*new_node;
	t_objl	*cur;

	if (objl == NULL || new_obj == NULL)
		return (-1);
	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (-1);
	new_node->obj = new_obj;
	new_node->next = NULL;
	if (*objl == NULL)
	{
		*objl = new_node;
		return (0);
	}
	cur = *objl;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new_node;
	return (0);
}
