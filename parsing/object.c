/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:09:44 by jdelattr          #+#    #+#             */
/*   Updated: 2026/02/24 15:54:47 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	pars_sphere(char **tab, t_rt_data *data)
{
	t_obj_lst	*obj;

	if (tab_len(tab) != 4)
		return (ERROR);
	obj = ft_lstnew_obj(SPHERE);
	if (pars_vect3(tab[1], &obj->u.sp.center) == -1)
		return (ERROR);
	if (!is_valid_number(tab[2]))
		return (ERROR);
	obj->u.sp.radius = ft_atof(tab[2]) / 2.0;
	if (obj->u.sp.radius <= 0)
		return (ERROR);
	if (pars_color(tab[3], &obj->u.sp.color) == -1)
		return (ERROR);
	if (data->obj_list == NULL)
		data->obj_list = obj;
	else
		ft_lstadd_back(&data->obj_list, obj);
	return (0);
}

int	pars_plane(char **tab, t_rt_data *data)
{
	t_obj_lst	*obj;

	if (tab_len(tab) != 4)
		return (ERROR);
	obj = ft_lstnew_obj(PLANE);
	if (pars_vect3(tab[1], &obj->u.pl.center) == -1)
		return (ERROR);
	if (pars_vect3(tab[2], &obj->u.pl.normal) == -1)
		return (ERROR);
	if (!check_vect(obj->u.pl.normal))
		return (ERROR);
	if (pars_color(tab[3], &obj->u.pl.color) == -1)
		return (ERROR);
	if (data->obj_list == NULL)
		data->obj_list = obj;
	else
		ft_lstadd_back(&data->obj_list, obj);
	return (0);
}

int	pars_cylinder(char **tab, t_rt_data *data)
{
	t_obj_lst	*obj;

	if (tab_len(tab) != 6)
		return (ERROR);
	obj = ft_lstnew_obj(CYLINDER);
	if (pars_vect3(tab[1], &obj->u.cy.center) == -1)
		return (ERROR);
	if (pars_vect3(tab[2], &obj->u.cy.axis) == -1)
		return (ERROR);
	if (!check_vect(obj->u.cy.axis))
		return (ERROR);
	if (!is_valid_number(tab[3]) || !is_valid_number(tab[4]))
		return (ERROR);
	obj->u.cy.diameter = ft_atof(tab[3]);
	obj->u.cy.height = ft_atof(tab[4]);
	if (obj->u.cy.diameter <= 0 || obj->u.cy.height <= 0)
		return (ERROR);
	if (pars_color(tab[5], &obj->u.cy.color) == -1)
		return (ERROR);
	if (data->obj_list == NULL)
		data->obj_list = obj;
	else
		ft_lstadd_back(&data->obj_list, obj);
	return (0);
}
