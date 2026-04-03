/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itxv_dlt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:29:46 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/03 12:30:28 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void	itxv_dlt(t_itxv *itxv)
{
	if (!itxv)
		return ;
	if (itxv->v)
		free(itxv->v);
	itxv->v = NULL;
	itxv->len = 0;
	itxv->cap = 0;
}
