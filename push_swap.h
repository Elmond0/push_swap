/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:35:59 by elmondo           #+#    #+#             */
/*   Updated: 2025/03/17 10:37:08 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_data
{
	int	value;
	int	index;	
}	t_data;

t_list	**create_list(int list_size, void **args);
void	print_list(t_list **head, char *list_name);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	check_small_stacks(t_list **stack_a, t_list **stack_b);
int		**parse_integer(int tab_size, char **nbrs);
int		**normalize_tab(int tab_size, int **tab);
int		is_sorted_list(t_list **node);
int		check_double(int **nbr);
int		check_limits(int **nbr);
int		check_numbers(char **nptr);
void	radix_sort(t_list **stack_a, t_list **stack_b);
void	free_all(t_list **stack_a, t_list **stack_b, int **ind, int **tab);
void	validate_input(char **av, int **tab);
int		bit_counter(int nbr);

#endif