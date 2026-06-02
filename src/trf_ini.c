/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trf_ini.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:05:49 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/02 11:28:53 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformations.h"

void	trf_ini(t_trf *trf)
{
	m44_idm(&(trf->tm));
	m44_idm(&(trf->itm));
	m44_idm(&(trf->itmt));
	m44_idm(&(trf->trlm));
	m44_idm(&(trf->sclm));
	m44_idm(&(trf->rotm));
	m44_idm(&(trf->shem));
	m44_idm(&(trf->itrlm));
	m44_idm(&(trf->isclm));
	m44_idm(&(trf->irotm));
	m44_idm(&(trf->ishem));
}
