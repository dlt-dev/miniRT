/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:20:23 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/26 16:06:01 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

int	mat_set(const t_mat *model, t_mat *subject)
{
	if (model->r != subject->r || model->c != subject->c || !(subject->m))
	{
		if (subject->m)
			mat_dlt(subject);
		subject->r = model->r;
		subject->c = model->c;
		if (!mat_crt(subject))
			return (-1);
	}
	return (0);
}
