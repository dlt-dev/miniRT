/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pat_trf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:06:25 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/02 13:18:55 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"

int	pat_trf(t_pat *pat, const t_trf *trf)
{
	if (!pat || !trf)
		return (-1);
	m44_cpy(&(trf->tm), &(pat->tm));
	m44_cpy(&(trf->itm), &(pat->itm));
	return (0);
}
