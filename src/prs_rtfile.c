/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_rtfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:39:53 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/28 14:03:29 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	valid_fname(const char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4)
		return (false);
	if (ft_strcmp(file + len - 3, ".rt") != 0)
		return (false);
	return (true);
}

// Returns -1 on error, 0 otherwise.
int	prs_rtfile(t_prs *prs)
{
	if (!valid_fname(prs->fname))
		return (ft_err_prt("Invalid extension !\
			expected : \"[filename].rt\"\n", -1));
	prs->fd = open(prs->fname, O_RDONLY);
	if (prs->fd < 0)
	{
		ft_err_prt("Could not open file : ", -1);
		ft_err_prt(prs->fname, -1);
		ft_err_prt("\n", -1);
		return (-1);
	}
	if (prs_lines(prs) < 0)
		return (close(prs->fd), -1);
	if (prs_cmplt(prs) < 0)
		return (close(prs->fd), -1);
	return (close(prs->fd), 0);
}
