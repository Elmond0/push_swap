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
		if (!ft_isdigit(nptr[i][0]))
		{
			if (nptr[i][0] != '+' && nptr[i][0] != '-')
				return (0);
		}
		j = 1;
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

int	check_limits(int **nbr)
{
	unsigned int	i;

	i = 0;
	while (nbr[i])
	{
		if (*(nbr[i]) < INT_MIN || *(nbr[i]) > INT_MAX)
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
