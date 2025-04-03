/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:34:16 by elmondo           #+#    #+#             */
/*   Updated: 2025/03/17 10:34:16 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		**tab;
	int		**ind;

	if (ac == 1)
		return (0);
	av++;
	tab = parse_integer(ac - 1, av);
	validate_input(av, tab);
	ind = normalize_tab(ac - 1, tab);
	stack_a = create_list(ac - 1, (void **)ind);
	stack_b = create_list(0, NULL);
	check_small_stacks(stack_a, stack_b);
	free_all(stack_a, stack_b, ind, tab);
	return (0);
}
