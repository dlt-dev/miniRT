/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgtv_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 09:39:51 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/22 14:16:26 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

int	lgtv_add(t_lgtv *lgtv, const t_lgt *light)
{
	t_lgt	*new_v;
	size_t	new_cap;

	if (!lgtv || !light)
		return (-1);
	if (lgtv->len >= lgtv->cap)
	{
		if (lgtv->cap == 0)
			new_cap = 1;
		else
			new_cap = lgtv->cap * 2;
		new_v = malloc(sizeof(t_lgt) * new_cap);
		if (!new_v)
			return (-1);
		memcpy(new_v, lgtv->v, sizeof(t_lgt) * lgtv->len);
		free(lgtv->v);
		lgtv->v = new_v;
		lgtv->cap = new_cap;
	}
	lgtv->v[lgtv->len] = *light;
	lgtv->len++;
	return (0);
}
