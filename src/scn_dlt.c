/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_dlt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:50:18 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 14:09:06 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	scn_dlt(t_scn *scene)
{
	wld_dlt(&(scene->world));
	itxv_dlt(&(scene->itxv));
	texv_dlt(&(scene->texv), &(scene->mlx));
	texv_dlt(&(scene->hmapv), &(scene->mlx));
}
