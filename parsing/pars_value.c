/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:00:17 by jdelattr          #+#    #+#             */
/*   Updated: 2026/02/24 16:00:38 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	pars_vect3(char *str, t_vect3 *v)
{
	char	**xyz;
	int		len;

	if (!str || !v)
		return (-1);
	xyz = ft_split(str, ',');
	len = tab_len(xyz);
	if (len != 3)
	{
		free_tab(xyz);
		return (-1);
	}
	if (!is_valid_number(xyz[0]) || !is_valid_number(xyz[1])
		|| !is_valid_number(xyz[2]))
	{
		free_tab(xyz);
		return (-1);
	}
	v->x = ft_atof(xyz[0]);
	v->y = ft_atof(xyz[1]);
	v->z = ft_atof(xyz[2]);
	free_tab(xyz);
	return (0);
}

int	pars_color(char *str, t_color *c)
{
	char	**rgb;
	int		len;

	if (!str || !c)
		return (-1);
	rgb = ft_split(str, ',');
	len = tab_len(rgb);
	if (len != 3)
	{
		free_tab(rgb);
		return (-1);
	}
	if (!is_valid_positive_int(rgb[0]) || !is_valid_positive_int(rgb[1])
		|| !is_valid_positive_int(rgb[2]))
	{
		free_tab(rgb);
		return (-1);
	}
	c->r = ft_atoi(rgb[0]);
	c->g = ft_atoi(rgb[1]);
	c->b = ft_atoi(rgb[2]);
	c->t = 0;
	free_tab(rgb);
	if (!check_color(*c))
		return (-1);
	return (0);
}
