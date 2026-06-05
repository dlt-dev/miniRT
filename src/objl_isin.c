/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objl_isin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 09:41:06 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/05 09:41:22 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

bool	objl_isin(const t_objl *objl, const t_obj *to_find)
{
	while (objl != NULL)
	{
		if (objl->obj == to_find)
			return (true);
		objl = objl->next;
	}
	return (false);
}
