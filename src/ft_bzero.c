/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 07:57:12 by cybourge          #+#    #+#             */
/*   Updated: 2026/04/29 07:57:19 by cybourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	adresse;

	adresse = 0;
	while (adresse < n)
	{
		((char *)s)[adresse] = 0;
		adresse++;
	}
}
