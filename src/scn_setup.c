/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:34:22 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/22 10:19:19 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	test_scn1(t_scn *scene);
int	test_scn2(t_scn *scene);
int	test_scn3(t_scn *scene);
int	test_scn4(t_scn *scene);

int	scn_setup(t_scn *scene)
{
	// if (scn_dflt_objs(&(scene->world)) < 0)
	// 	return (-1);
	// if (scn_dflt_lgts(&(scene->world)) < 0)
	// 	return (-1);
	// if (scn_dflt_cam(&(scene->camera)) < 0)
	// 	return (-1);
	if (test_scn4(scene) == -1)
		return (-1);
	scene->itxv = itxv_crt(10);
	if (scene->itxv.v == NULL)
		return (-1);
	return (0);
}
