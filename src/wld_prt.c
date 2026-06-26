/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wld_prt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:00:53 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/26 10:10:15 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

void	wld_prt(const t_wld *wld)
{
	if (!wld)
		return ;
	printf("World :\n");
	objv_prt(&(wld->objs));
	printf("Ambient Light : (%.3lf,%.3lf,%.3lf,%.3lf)\n",
		wld->amb.clr.t, wld->amb.clr.r, wld->amb.clr.g, wld->amb.clr.b);
	lgtv_prt(&(wld->lgts));
}
