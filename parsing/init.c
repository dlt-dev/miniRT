/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:28:10 by jdelattr          #+#    #+#             */
/*   Updated: 2026/02/21 15:29:23 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	init_rt_data(t_rt_data *data)
{
	ft_bzero(data, sizeof(t_rt_data));
	data->ambient.count = 0;
	data->camera.count = 0;
	data->light.count = 0;
	data->obj_list = NULL;
	data->obj_tab = NULL;
	data->obj_count = 0;
}

int	fill_tab(t_obj_lst *lst, t_object *tab, int i)
{
	if (lst->obj_type == SPHERE)
	{
		tab[i].type = SPHERE;
		tab[i].u.sp = lst->u.sp;
	}
	else if (lst->obj_type == PLANE)
	{
		tab[i].type = PLANE;
		tab[i].u.pl = lst->u.pl;
	}
	else if (lst->obj_type == CYLINDER)
	{
		tab[i].type = CYLINDER;
		tab[i].u.cy = lst->u.cy;
	}
	else
		return (ERROR);
	return (0);
}

int	init_obj_tab(t_rt_data *data)
{
	t_obj_lst	*lst;
	t_object	*tab;
	int			i;

	i = 0;
	lst = data->obj_list;
	tab = malloc(sizeof(t_object) * ft_lstsize(lst));
	if (tab == NULL)
		return (ERROR);
	data->obj_count = ft_lstsize(lst);
	while (lst != NULL && i < data->obj_count)
	{
		if (fill_tab(lst, tab, i) == ERROR)
			return (ERROR);
		lst = lst->next;
		i++;
	}
	ft_free_lst(&data->obj_list);
	data->obj_tab = tab;
	return (0);
}
