/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:35:23 by elmondo           #+#    #+#             */
/*   Updated: 2025/03/17 10:35:23 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_list(t_list **node)
{
	t_list	*current;

	current = *node;
	while (current && current->next)
	{
		if (*(int *)(current->content) > *(int *)(current->next->content))
			return (0);
		current = current->next;
	}
	print_list(node, "sorted");
	return (1);
}

static void	sort_three(t_list **stack_a)
{
	int	value[3];

	if (ft_lstsize(*stack_a) != 3)
		return ;
	if (is_sorted_list(stack_a))
		return ;
	value[0] = *(int *)((*stack_a)->content);
	value[1] = *(int *)((*stack_a)->next->content);
	value[2] = *(int *)((*stack_a)->next->next->content);
	if (value[0] > value[1] && value[0] < value[2])
		sa(stack_a);
	else if (value[0] > value[1] && value[1] > value[2])
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (value[0] > value[2] && value[1] < value[2])
		ra(stack_a);
	else if (value[0] < value[1] && value[0] > value[2])
		rra(stack_a);
	else if (value[0] < value[2] && value[1] > value[2])
	{
		sa(stack_a);
		ra(stack_a);
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	count;

	count = 0;
	while (count < 2)
	{
		if (*(int *)((*stack_a)->content) < 2)
		{
			count++;
			pb(stack_a, stack_b);
		}
		else
			ra(stack_a);
	}
	if (!is_sorted_list(stack_b))
		sb(stack_b);
	if (ft_lstsize(*stack_a) == 2)
	{
		if (!is_sorted_list(stack_a))
			sa(stack_a);
	}
	else
		sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	check_small_stacks(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 1)
		exit (EXIT_SUCCESS);
	else if (size == 2)
	{
		if (!is_sorted_list(stack_a))
			sa(stack_a);
	}
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 5 || size == 4)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
