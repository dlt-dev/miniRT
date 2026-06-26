/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtl_prt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 09:47:35 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/26 09:56:18 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

void	mtl_prt(const t_mtl *mtl)
{
	printf("Material Properties: ");
	printf("Color: (%.3lf,%.3lf,%.3lf,%.3lf); ",
		mtl->clr.t, mtl->clr.r, mtl->clr.g, mtl->clr.b);
	printf("Ambient: %.3lf; Diffuse: %.3lf; Specular: %.3lf; ",
		mtl->amb, mtl->dif, mtl->spc);
	printf("Shininess: %.3lf; ", mtl->shi);
	printf("Reflection: %.3lf; Transparency: %.3lf; Refraction: %.3lf;\n",
		mtl->rfl, mtl->tsp, mtl->ref);
}
