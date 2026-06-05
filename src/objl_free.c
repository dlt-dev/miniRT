/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objl_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 09:41:57 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/05 09:42:06 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

void	objl_free(t_objl *objl)
{
	t_objl	*next;

	while (objl != NULL)
	{
		next = objl->next;
		free(objl);
		objl = next;
	}
}
