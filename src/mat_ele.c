/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_ele.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:01:17 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/26 15:44:12 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

int	mat_ele(const t_mat *m1, unsigned int i, unsigned int j, double *ele)
{
	if (!m1 || !m1->m || !ele)
		return (-1);
	if (i >= m1->r || j >= m1->c)
		return (-1);
	*ele = m1->m[i * m1->c + j];
	return (0);
}
