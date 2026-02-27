/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_obj_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:47:42 by jdelattr          #+#    #+#             */
/*   Updated: 2026/02/21 15:41:30 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_obj_lst	*ft_lstnew_obj(int type)
{
	t_obj_lst	*node;

	node = (t_obj_lst *)malloc(sizeof(t_obj_lst));
	if (node == NULL)
		return (NULL);
	node->obj_type = type;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_obj_lst **lst, t_obj_lst *new)
{
	t_obj_lst	*last;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

t_obj_lst	*ft_lstlast(t_obj_lst *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize(t_obj_lst *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
