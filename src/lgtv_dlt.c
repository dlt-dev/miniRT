/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgtv_dlt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 09:37:09 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/22 09:38:01 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

void	lgtv_dlt(t_lgtv *lgtv)
{
	if (!lgtv)
		return ;
	free(lgtv->v);
	lgtv->v = NULL;
	lgtv->len = 0;
	lgtv->cap = 0;
}
