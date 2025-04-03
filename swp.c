/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:35:38 by elmondo           #+#    #+#             */
/*   Updated: 2025/03/17 10:35:38 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_s(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	sa(t_list **stack_a)
{
	ft_s(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	ft_s(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	ft_s(stack_a);
	ft_s(stack_b);
	write(1, "ss\n", 3);
}
