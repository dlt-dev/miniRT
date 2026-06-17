/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:34:22 by cybourge          #+#    #+#             */
/*   Updated: 2026/06/17 12:19:48 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Returns a function pointer to the function 
// that can parse the identifier's line.
// Returns NULL if no match is found.
static t_parsef	match_obj_id(const char *identifier)
{
	static const t_prs_func	parsef_list[] = {
	{"A", prs_ambient},
	{"C", prs_camera},
	{"L", prs_light},
	{"sp", prs_sphere},
	{"pl", prs_plane},
	{"cy", prs_cylinder},
	{"co", prs_cone},
	{NULL, NULL}
	};
	size_t					i;

	i = 0;
	while (parsef_list[i].id != NULL)
	{
		if (!ft_strcmp(identifier, parsef_list[i].id))
			return (parsef_list[i].func);
		i++;
	}
	return (NULL);
}

// Returns -1 on error, 0 othewise.
static int	prs_line(t_prs *prs, const char *line)
{
	char		**ltab;
	t_parsef	fun;

	ltab = ft_split(line, " \t");
	if (!ltab)
		return (-1);
	if (tab_len(ltab) == 0)
		return (tab_dlt(ltab), 0);
	fun = match_obj_id(ltab[0]);
	if (!fun)
	{
		ft_err_prt("Invalid Identifier detected : ", -1);
		ft_err_prt(ltab[0], -1);
		ft_err_prt("\n", -1);
		return (tab_dlt(ltab), -1);
	}
	if (fun(prs, ltab) < 0)
		return (tab_dlt(ltab), -1);
	tab_dlt(ltab);
	return (0);
}

// Returns -1 on error, 0 otherwise.
int	prs_lines(t_prs *prs)
{
	char	*line;
	size_t	len;

	line = gnl(prs->fd);
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (len > 0 && line[0] == '#')
		{
			free(line);
			line = gnl(prs->fd);
			continue ;
		}
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (prs_line(prs, line) == -1)
		{
			free(line);
			gnl(GNL_CLEAR);
			return (-1);
		}
		free(line);
		line = gnl(prs->fd);
	}
	return (0);
}
