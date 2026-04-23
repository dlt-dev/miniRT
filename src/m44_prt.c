/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m44_prt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 09:19:57 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 12:16:27 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	m44_prt(const t_m44 *m1)
{
	char	buf[4][4][64];
	int		col_width[4];

	if (!m1)
		return ;
	m44_fill_buf(m1, buf);
	m44_fill_widths(buf, col_width);
	m44_print_rows(buf, col_width);
}
