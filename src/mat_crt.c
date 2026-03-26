/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_crt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:58:00 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/26 16:04:48 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat	*mat_crt(t_mat *m1)
{
	size_t	len;

	if (!m1 || m1->r <= 0 || m1->c <= 0)
		return (NULL);
	len = sizeof(double) * m1->r * m1->c;
	m1->m = malloc(len);
	if (!m1->m)
		return (NULL);
	ft_memset(m1->m, 0, len);
	return (m1);
}
