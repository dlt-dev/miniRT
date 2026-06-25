/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texv_add_ftex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 09:48:30 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 11:20:40 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

int	texv_add_ftex(t_texv *texv, char *fpath, t_mlx_data *data)
{
	t_tex	*new_v;
	size_t	new_cap;

	if (!texv || !fpath || !data)
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
	if (ftex_load(&(texv->v[texv->len].u_tex.ftex), fpath, data) == -1)
		return (-1);
	texv->v[texv->len].type = FILE_TEX;
	texv->len++;
	return (0);
}
