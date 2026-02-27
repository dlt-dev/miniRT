/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:28:04 by jdelattr          #+#    #+#             */
/*   Updated: 2026/02/21 15:49:30 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}

int	ft_atoi(const char *s)
{
	int	result;
	int	i;
	int	signe;

	result = 0;
	i = 0;
	signe = 1;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
	{
		i++;
	}
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			signe = signe * -1;
		i++;
	}
	while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result * signe);
}

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

double	ft_atof(const char *str)
{
	double	result;
	double	sign;
	double	fraction;
	double	divisor;

	result = 0.0;
	sign = 1.0;
	fraction = 0.0;
	divisor = 10.0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1.0;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10.0 + (*str++ - '0');
	if (*str == '.')
		while (*++str >= '0' && *str <= '9')
		{
			fraction += (*str - '0') / divisor;
			divisor *= 10.0;
		}
	return (sign * (result + fraction));
}
