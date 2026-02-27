/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:50:52 by jdelattr          #+#    #+#             */
/*   Updated: 2026/02/27 12:13:01 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4)
		return (ERROR);
	if (ft_strcmp(file + len - 3, ".rt") != 0)
		return (ERROR);
	return (0);
}

int	pars_line(char *line, t_rt_data *data)
{
	char	**tab;
	int		ret;

	tab = ft_split(line, ' ');
	ret = ERROR;
	if (!tab || !tab[0])
		return (free_tab(tab), 0);
	if (!ft_strcmp(tab[0], "A"))
		ret = pars_ambient(tab, data);
	else if (!ft_strcmp(tab[0], "C"))
		ret = pars_camera(tab, data);
	else if (!ft_strcmp(tab[0], "L"))
		ret = pars_light(tab, data);
	else if (!ft_strcmp(tab[0], "sp"))
		ret = pars_sphere(tab, data);
	else if (!ft_strcmp(tab[0], "pl"))
		ret = pars_plane(tab, data);
	else if (!ft_strcmp(tab[0], "cy"))
		ret = pars_cylinder(tab, data);
	free_tab(tab);
	return (ret);
}

int	main(int ac, char **av) // int pars_rt() a appeler dans le main
{
	int			fd;
	char		*line;
	t_rt_data	data;
	int			len;

	init_rt_data(&data);
	if (ac != 2)
		return (print_err_free("A [file].rt only is requested", &data));
	if (check_file(av[1]) == ERROR)
		return (print_err_free("Invalid file name", &data));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (print_err_free("I can't open the file", &data));
	while ((line = get_next_line(fd)))
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (*line)
		{
			if (pars_line(line, &data) == ERROR)
			{
				free(line);
				return (print_err_free("the content of [file].rt is incorrect",
						&data));
			}
		}
		free(line);
	}
	close(fd);
	if (data.camera.count == 0 || data.light.count == 0
		|| data.ambient.count == 0)
		return (print_err_free("A parameter is missing.", &data));
	if (init_obj_tab(&data) == ERROR)
		return (print_err_free("The allocation of the object array failed.",
				&data));
	print_datatest(&data); /// test
	free_all(&data); /// test
	return (0);
}
