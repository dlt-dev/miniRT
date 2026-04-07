/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v4_prt_uop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:50:36 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/07 12:06:25 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector4.h"

void	v4_prt_uop(const t_v4 *v1, const t_v4 *v2, const char *op)
{
	int	pad_len;

	if (!v1 || !v2 || !op)
		return ;
	pad_len = (int) strlen(op);
	printf(
		"%*s ╭ %8.3f ╮   ╭ %8.3f ╮\n"
		"%s | %8.3f | = | %8.3f |\n"
		"%*s | %8.3f |   | %8.3f |\n"
		"%*s ╰ %8.3f ╯   ╰ %8.3f ╯\n",
		pad_len, "", v1->x, v2->x,
		op, v1->y, v2->y,
		pad_len, "", v1->z, v2->z,
		pad_len, "", v1->w, v2->w
		);
}
