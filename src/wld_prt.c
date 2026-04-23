/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wld_prt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:00:53 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/22 14:09:36 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

void	wld_prt(const t_wld *wld)
{
	if (!wld)
		return ;
	printf("World :\n");
	objv_prt(&(wld->objs));
	lgtv_prt(&(wld->lgts));
}
