/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:34:22 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/27 10:16:56 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static int	pat_setup(t_pat *pat, t_scn *scene)
// {
// 	*pat = (t_pat){.pat = pat_strp1,
// 		.clr1 = clr_unpack(RED), .clr2 = clr_unpack(BLUE)};
// 	if (texv_add_pat(&(scene->texv), pat) == -1)
// 		return (-1);
// 	*pat = (t_pat){.pat = pat_lgrad1,
// 		.clr1 = clr_unpack(RED), .clr2 = clr_unpack(WHITE)};
// 	if (texv_add_pat(&(scene->texv), pat) == -1)
// 		return (-1);
// 	*pat = (t_pat){.pat = pat_ring1,
// 		.clr1 = clr_unpack(BLUE), .clr2 = clr_unpack(WHITE)};
// 	if (texv_add_pat(&(scene->texv), pat) == -1)
// 		return (-1);
// 	*pat = (t_pat){.pat = pat_chkr1,
// 		.clr1 = clr_unpack(RED), .clr2 = clr_unpack(WHITE)};
// 	if (texv_add_pat(&(scene->texv), pat) == -1)
// 		return (-1);
// 	return (0);
// }

// static int	tex_setup(t_scn *scene)
// {
// 	const size_t	tex_nb = 5;
// 	t_pat			pat;

// 	scene->texv = texv_crt(tex_nb);
// 	if (scene->texv.v == NULL)
// 		return (-1);
// 	scene->texv.len = 0;
// 	if (pat_setup(&pat, scene) == -1)
// 		return (-1);
// 	if (texv_add_ftex(&(scene->texv), "tex/earth.xpm", &(scene->mlx)) == -1)
// 		return (-1);
// 	return (0);
// }

// static int	hmap_setup(t_scn *scene)
// {
// 	const size_t	nb_hmap = 1;

// 	scene->hmapv = texv_crt(nb_hmap);
// 	if (scene->hmapv.v == NULL)
// 		return (-1);
// 	scene->hmapv.len = 0;
// 	if (texv_add_ftex(&(scene->hmapv), "tex/bump.xpm", &(scene->mlx)) == -1)
// 		return (-1);
// 	return (0);
// }

int	test_scn4(t_scn *scene);

int	scn_setup(t_scn *scene)
{
	// if (tex_setup(scene) == -1)
	// 	return (-1);
	// if (hmap_setup(scene) == -1)
	// 	return (-1);
	// if (scn_dflt_objs(&(scene->world), scene) < 0)
	// 	return (-1);
	// if (scn_dflt_lgts(&(scene->world)) < 0)
	// 	return (-1);
	// if (scn_dflt_cam(&(scene->camera)) < 0)
	// 	return (-1);
	if (test_scn4(scene) < 0)
		return (-1);
	return (0);
}
