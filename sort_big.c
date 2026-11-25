/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:35:04 by elmondo           #+#    #+#             */
/*   Updated: 2025/03/17 10:37:25 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**normalize_tab(int tab_size, int **tab)
{
	int	i;
	int	j;
	int	**norm;
	int	value;

	norm = malloc(sizeof(int *) * tab_size);
	if (!norm)
		return (NULL);
	i = 0;
	while (i < tab_size)
	{
		value = *tab[i];
		j = 0;
		norm[i] = ft_calloc(1, sizeof(int));
		if (!norm[i])
			return (ft_free((void **)norm, i), NULL);
		while (j < tab_size)
		{
			if (*tab[j] < value)
				*norm[i] = *norm[i] + 1;
			j++;
		}
		i++;
	}
	return (norm);
}

static int	bit_counter(int nbr)
{
	int	bits;

	bits = 0;
	while (nbr)
	{
		bits++;
		nbr >>= 1;
	}
	return (bits);
}

static void	radix_pass(t_list **stack_a, t_list **stack_b, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((*(int *)((*stack_a)->content) >> bit) & 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		i++;
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	bits;
	int	bit;

	size = ft_lstsize(*stack_a);
	bits = bit_counter(size - 1);
	bit = 0;
	while (bit < bits && !is_sorted_list(stack_a))
	{
		radix_pass(stack_a, stack_b, bit, size);
		bit++;
	}
}
