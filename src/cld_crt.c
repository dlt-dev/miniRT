/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cld_crt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:58:25 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/17 12:33:12 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_obj	cld_crt(void)
{
	t_obj	cylinder;
	
	cylinder.type = CYLINDER;
	cylinder.u_o.cy.closed = true;
	cylinder.u_o.cy.min = 0;
	cylinder.u_o.cy.max = 1;
	m44_idm(&(cylinder.tm));
	m44_idm(&(cylinder.itm));
	m44_idm(&(cylinder.itmt));
	mtl_ini(&(cylinder.mtrl));
	cylinder.hit = cld_hit;
	cylinder.nrml = cld_nrml;
	return (cylinder);
}
