/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texv_crt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 09:09:05 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 09:11:29 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

t_texv	texv_crt(size_t cap)
{
	t_texv	texv;

	texv.len = 0;
	texv.cap = cap;
	if (cap == 0)
	{
		texv.v = NULL;
		return (texv);
	}
	texv.v = malloc(sizeof(t_tex) * cap);
	if (!texv.v)
	{
		texv.cap = 0;
		return (texv);
	}
	return (texv);
}
