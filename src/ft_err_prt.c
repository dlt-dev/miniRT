/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_prt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:30:14 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/30 11:31:22 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_err_prt(const char *msg, int ret)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	return (ret);
}
