/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texv_dlt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 09:11:46 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/25 17:09:22 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

void	texv_dlt(t_texv *texv, t_mlx_data *data)
{
	size_t	i;

	if (!texv)
		return ;
	i = 0;
	while (i < texv->len)
	{
		if (texv->v[i].type == FILE_TEX)
			ftex_dlt(&(texv->v[i].u_tex.ftex), data);
		i++;
	}
	free(texv->v);
	texv->cap = 0;
	texv->len = 0;
}
