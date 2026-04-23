/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_prt_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:53:45 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 13:55:16 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	m44_print_row_left(t_m44_vprd_disp *d, int row,
		const char *left, const char *right)
{
	int		col;

	printf("%s", left);
	col = 0;
	while (col < 4)
	{
		printf(" %*s", d->m_w[col], d->m_buf[row][col]);
		col++;
	}
	printf(" %s", right);
	if (row == 1)
		printf(" * ");
	else
		printf("   ");
	printf("%s %*s %s", left, d->v_w[0], d->v1_buf[row], right);
	if (row == 1)
		printf(" = ");
	else
		printf("   ");
}

void	m44_print_row_right(t_m44_vprd_disp *d, int row,
		const char *left, const char *right)
{
	printf("%s %*s %s\n", left, d->v_w[1], d->v2_buf[row], right);
}
