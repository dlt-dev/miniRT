/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texv_add_pat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 09:58:43 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 11:33:08 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

int	texv_add_pat(t_texv *texv, const t_pat *pat)
{
	t_tex	*new_v;
	size_t	new_cap;

	if (!texv || !pat)
		return (-1);
	if (texv->len >= texv->cap)
	{
		if (texv->cap == 0)
			new_cap = 1;
		else
			new_cap = texv->cap * 2;
		new_v = malloc(sizeof(t_tex) * new_cap);
		if (!new_v)
			return (-1);
		ft_memcpy(new_v, texv->v, sizeof(t_tex) * texv->cap);
		free(texv->v);
		texv->v = new_v;
		texv->cap = new_cap;
	}
	texv->v[texv->len].u_tex.ptex = *pat;
	texv->v[texv->len].type = PATTERN_TEX;
	texv->len++;
	return (0);
}
