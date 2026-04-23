/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v4_prt_bop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:43:22 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/23 10:56:24 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector4.h"

void	v4_prt_bop(
	const t_v4 *v1,
	const t_v4 *v2,
	const t_v4 *v3,
	const char *op)
{
	int	pad_len;

	if (!v1 || !v2 || !v3 || !op)
		return ;
	pad_len = (int) strlen(op);
	printf(
		"╭ %8.3f ╮ %*s ╭ %8.3f ╮   ╭ %8.3f ╮\n"
		"│ %8.3f │ %s | %8.3f | = | %8.3f |\n"
		"│ %8.3f │ %*s | %8.3f |   | %8.3f |\n"
		"╰ %8.3f ╯ %*s ╰ %8.3f ╯   ╰ %8.3f ╯\n",
		v1->x, pad_len, "", v2->x, v3->x,
		v1->y, op, v2->y, v3->y,
		v1->z, pad_len, "", v2->z, v3->z,
		v1->w, pad_len, "", v2->w, v3->w
		);
}
