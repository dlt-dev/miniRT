/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_ele.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 10:17:03 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/31 10:17:06 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

int	m44_ele(const t_m44 *m1, unsigned int i, unsigned int j, double *ele)
{
	if (!m1 || !ele || i >= M44_SIZE || j >= M44_SIZE)
		return (-1);
	*ele = (*m1)[i * M44_SIZE + j];
	return (0);
}
