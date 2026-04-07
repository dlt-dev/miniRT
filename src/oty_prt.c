/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oty_prt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 09:06:47 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/07 09:07:59 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

const char	*oty_prt(t_oty type)
{
	static const char	*types[] = {
		"Undefined",
		"Sphere",
		"Plane",
		"Cylinder"
	};

	if (type < DEFAULT || type > CYLINDER)
		return ("Invalid Object");
	return (types[type]);
}
