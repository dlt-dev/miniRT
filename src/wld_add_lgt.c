/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wld_add_lgt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:59:09 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/22 14:07:36 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

int	wld_add_lgt(t_wld *wld, const t_lgt *light)
{
	if (!wld || !light)
		return (-1);
	lgtv_add(&(wld->lgts), light);
	return (0);
}
