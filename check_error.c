/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:34:06 by elmondo           #+#    #+#             */
/*   Updated: 2025/03/17 10:34:06 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_numbers(char **nptr)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (nptr[i])
	{
		j = 0;
		if (nptr[i][0] == '+' || nptr[i][0] == '-')
			j = 1;
		if (!nptr[i][j])
			return (0);
		while (nptr[i][j])
		{
			if (!ft_isdigit(nptr[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	in_limits(char *str)
{
	long long	nbr;
	int			neg;

	neg = (*str == '-');
	if (*str == '-' || *str == '+')
		str++;
	nbr = 0;
	while (*str)
	{
		nbr = nbr * 10 + (*str - '0');
		if (nbr > 2147483648LL)
			return (0);
		str++;
	}
	if (neg)
		return (nbr <= 2147483648LL);
	return (nbr <= INT_MAX);
}

int	check_limits(char **nptr)
{
	unsigned int	i;

	i = 0;
	while (nptr[i])
	{
		if (!in_limits(nptr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_double(int **nbr)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (nbr[i])
	{
		j = 1;
		while (nbr[i + j])
		{
			if (*(nbr[i]) == *(nbr[i + j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
