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

static int	get_pos(t_list *lst, int target)
{
	int	pos;

	pos = 0;
	while (lst && *(int *)(lst->content) != target)
	{
		lst = lst->next;
		pos++;
	}
	return (pos);
}

static void	push_chunks(t_list **stack_a, t_list **stack_b, int chunk)
{
	int	pushed;
	int	value;

	pushed = 0;
	while (*stack_a)
	{
		value = *(int *)((*stack_a)->content);
		if (value <= pushed)
		{
			pb(stack_a, stack_b);
			if (ft_lstsize(*stack_b) > 1)
				rb(stack_b);
			pushed++;
		}
		else if (value <= pushed + chunk)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
	}
}

static void	bring_max(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	pos;

	size = ft_lstsize(*stack_b);
	pos = get_pos(*stack_b, size - 1);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(stack_b);
	}
	else
	{
		while (pos++ < size)
			rrb(stack_b);
	}
	pa(stack_a, stack_b);
}

void	chunk_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	chunk;

	size = ft_lstsize(*stack_a);
	if (size <= 150)
		chunk = size / 8;
	else
		chunk = size / 14;
	if (chunk < 1)
		chunk = 1;
	push_chunks(stack_a, stack_b, chunk);
	while (*stack_b)
		bring_max(stack_a, stack_b);
}
