/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objl_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 09:41:33 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/05 10:19:38 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

const t_obj	*objl_last(const t_objl *objl)
{
	if (objl == NULL)
		return (NULL);
	while (objl->next != NULL)
		objl = objl->next;
	return (objl->obj);
}
