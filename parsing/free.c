/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:02:08 by jdelattr          #+#    #+#             */
/*   Updated: 2026/02/21 15:31:18 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	print_err_free(char *message, t_rt_data *data)
{
	free_all(data);
	printf("Error\n");
	printf("%s\n", message);
	return (ERROR);
}

void	free_all(t_rt_data *data)
{
	if (!data)
		return ;
	if (data->obj_list)
	{
		ft_free_lst(&data->obj_list);
		data->obj_list = NULL;
	}
	if (data->obj_tab)
	{
		free(data->obj_tab);
		data->obj_tab = NULL;
	}
	data->obj_count = 0;
}

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_lst(t_obj_lst **lst)
{
	t_obj_lst	*tmp;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
