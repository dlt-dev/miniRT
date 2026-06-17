/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_mat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 08:47:31 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/16 16:36:47 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	check_n_write(t_mtl *mat, char **abcd)
{
	mat->amb = ft_atof(abcd[0]);
	if (!(mat->amb >= 0.0 && mat->amb <= 1.0))
		return (ft_err_prt("Material Ambient must be in [0, 1.0]\n", -1));
	mat->dif = ft_atof(abcd[1]);
	if (!(mat->dif >= 0.0 && mat->dif <= 1.0))
		return (ft_err_prt("Material Specular must be in [0, 1.0]\n", -1));
	mat->spc = ft_atof(abcd[2]);
	if (!(mat->spc >= 0.0 && mat->spc <= 1.0))
		return (ft_err_prt("Material Diffuse must be in [0, 1.0]\n", -1));
	mat->shi = ft_atof(abcd[3]);
	if (!(mat->shi > 0.0))
		return (ft_err_prt("Material Shininess must be > 0.0\n", -1));
	mat->rfl = ft_atof(abcd[4]);
	if (!(mat->rfl >= 0.0 && mat->rfl <= 1.0))
		return (ft_err_prt("Material Reflectiveness must be in [0, 1]\n", -1));
	mat->tsp = ft_atof(abcd[5]);
	if (!(mat->tsp >= 0.0 && mat->tsp <= 1.0))
		return (ft_err_prt("Material Transparency must be in [0, 1]\n", -1));
	mat->ref = ft_atof(abcd[6]);
	if (!(mat->ref >= 1.0))
		return (ft_err_prt("Material Refraction Index must be >= 1.0\n", -1));
	return (0);
}

// Parses an objects material data given in string form :
// "a,b,c,d,e,f,g" where :
// a = ambient light effect.
// b = specular light effect.
// c = diffuse light effect.
// d = shininess of the object.
// e = reflectivness of the object
// f = transparency of the object
// g = refraction index of the object
// writes the results in v.
// Returns -1 on error, 0 otherwise.
int	prs_mat(const char *str, t_mtl *mat)
{
	char	**abcd;
	int		len;

	if (!str || !mat)
		return (-1);
	abcd = ft_split(str, ",");
	len = tab_len(abcd);
	if (len != 7)
	{
		tab_dlt(abcd);
		return (-1);
	}
	if (!is_validf(abcd[0]) || !is_validf(abcd[1])
		|| !is_validf(abcd[2]) || !is_validf(abcd[3]) || !is_validf(abcd[4])
		|| !is_validf(abcd[5]) || !is_validf(abcd[6]))
	{
		tab_dlt(abcd);
		return (-1);
	}
	if (check_n_write(mat, abcd) == -1)
	{
		tab_dlt(abcd);
		return (-1);
	}
	tab_dlt(abcd);
	return (0);
}
