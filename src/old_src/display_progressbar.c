/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_progressbar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:10:10 by cybourge          #+#    #+#             */
/*   Updated: 2026/01/30 17:02:44 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Function to display the progress bar 0.1
void	display_progressbar(double percent)
{
	int	filled;
	int	i;

	filled = (int)(percent * BAR_WIDTH);
	write(1, "\r\e[1;37m[", 2 + 8);
	if (percent < 1.0)
		write(1, "\e[34m", 6);
	else
		write(1, "\e[32m", 6);
	i = 0;
	while (i++ < filled)
		write(1, "=", 1);
	while (i++ < BAR_WIDTH)
		write(1, " ", 1);
	if (percent < 1.0)
	{
		write(1, "\e[37m] Generating Image - ", 21 + 6);
		ft_putnbr((int)(percent * 100));
		write(1, "%", 1);
	}
	else
	{
		write(1, "\e[37m] \e[1;32m Image Generated !    ", 23 + 8 + 6);
		write(1, "\e[0m", 4);
	}
}
