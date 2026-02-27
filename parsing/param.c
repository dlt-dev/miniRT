/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:21:59 by jdelattr          #+#    #+#             */
/*   Updated: 2026/02/24 16:05:20 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	pars_ambient(char **tab, t_rt_data *data)
{
	if (tab_len(tab) != 3)
		return (ERROR);
	if (!is_valid_number(tab[1]))
		return (ERROR);
	data->ambient.ratio = ft_atof(tab[1]);
	if (data->ambient.ratio < 0 || data->ambient.ratio > 1)
		return (ERROR);
	if (pars_color(tab[2], &data->ambient.color) == -1)
		return (ERROR);
	data->ambient.count += 1;
	return (0);
}

int	pars_camera(char **tab, t_rt_data *data)
{
	if (tab_len(tab) != 4)
		return (ERROR);
	if (pars_vect3(tab[1], &data->camera.camera_loc) == -1)
		return (ERROR);
	if (pars_vect3(tab[2], &data->camera.orientation_vect) == -1)
		return (ERROR);
	if (!check_vect(data->camera.orientation_vect))
		return (ERROR);
	if (!is_valid_positive_int(tab[3]))
		return (ERROR);
	data->camera.fov = ft_atoi(tab[3]);
	if (data->camera.fov <= 0 || data->camera.fov >= 180)
		return (ERROR);
	data->camera.count += 1;
	return (0);
}

int	pars_light(char **tab, t_rt_data *data)
{
	if (tab_len(tab) != 4)
		return (ERROR);
	if (pars_vect3(tab[1], &data->light.light_loc) == -1)
		return (ERROR);
	if (!is_valid_number(tab[2]))
		return (ERROR);
	data->light.ratio = ft_atof(tab[2]);
	if (data->light.ratio < 0 || data->light.ratio > 1)
		return (ERROR);
	if (pars_color(tab[3], &data->light.color) == -1)
		return (ERROR);
	data->light.count += 1;
	return (0);
}
