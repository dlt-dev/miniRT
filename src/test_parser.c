/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 08:15:36 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/30 09:31:01 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
int	main(int argc, char **argv)
{
	t_scn	scene;
	t_prs	parser;

	if (argc < 2)
	{
		printf("Return a default scene.\n");
		return (1);
	}
	else if (argc > 2)
	{
		printf("Too many files given in argument\n");
		return (1);
	}
	parser.scn = &scene;
	memset(&scene, 0, sizeof(t_scn));
	parser.fname = argv[1];
	parser.amb_count = 0;
	parser.cam_count = 0;
	if (prs_rtfile(&parser) == -1)
	{
		scn_dlt(&scene);
		printf("Error Encountered\n");
		return (1);
	}
	prs_prt(&parser); // debug print to check results.
	scn_dlt(&scene);
	return (0);
}
*/
