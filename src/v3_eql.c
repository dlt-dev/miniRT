/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_eql.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 08:58:41 by cybourge          #+#    #+#             */
/*   Updated: 2026/03/26 09:59:43 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

bool	deql(double a, double b)
{
	return (fabs(a - b) < EPS);
}

bool	v3_eql(t_v3 a, t_v3 b)
{
	return (deql(a.x, b.x) && deql(a.y, b.y) && deql(a.z, b.z));
}
