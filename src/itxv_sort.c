/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itxv_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:40:33 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/03 13:08:18 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

static void	swap(t_itx *a, t_itx *b)
{
	t_itx	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(t_itx *arr, int low, int high)
{
	double	pivot;
	int		i;
	int		j;

	pivot = arr[high].t;
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j].t < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

static void	quicksort(t_itx *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

void	itxv_sort(const t_itxv *itxv)
{
	if (!itxv || itxv->len < 2)
		return ;
	quicksort(itxv->v, 0, (int)itxv->len - 1);
}
