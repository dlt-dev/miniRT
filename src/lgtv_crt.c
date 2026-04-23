/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgtv_crt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 09:35:09 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/22 14:16:17 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_lgtv	lgtv_crt(size_t cap)
{
	t_lgtv	lgtv;

	lgtv.len = 0;
	lgtv.cap = cap;
	if (cap == 0)
	{
		lgtv.v = NULL;
		return (lgtv);
	}
	lgtv.v = malloc(sizeof(t_lgt) * cap);
	if (!lgtv.v)
	{
		lgtv.cap = 0;
		return (lgtv);
	}
	return (lgtv);
}
