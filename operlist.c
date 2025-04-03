/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:34:08 by elmondo           #+#    #+#             */
/*   Updated: 2025/03/16 22:59:58 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**parse_integer(int tab_size, char **nbrs)
{
	int	**tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int *) * (tab_size + 1));
	if (!tab)
		return (NULL);
	while (i < tab_size)
	{
		tab[i] = malloc(sizeof(int));
		if (!tab[i])
			return (ft_free((void **)tab, i), NULL);
		*tab[i] = ft_atoi(nbrs[i]);
		i++;
	}
	tab[tab_size] = NULL;
	return (tab);
}

void	print_list(t_list **head, char *list_name)
{
	t_list	*node;
	int		value;
	int		i;

	if (!head)
		return ;
	i = 1;
	node = *head;
	ft_printf("\n------------%s---------------\n", list_name);
	while (node)
	{
		value = *(int *)node->content;
		ft_printf("node %d: \n", i);
		ft_printf("content: %d\n", value);
		ft_printf("next: %p\n", node->next);
		node = node->next;
		i++;
	}
	ft_printf("------------%s---------------\n\n", list_name);
}

t_list	**create_list(int list_size, void **args)
{
	t_list	**head;
	t_list	*node;
	int		i;

	head = (t_list **)malloc(sizeof(t_list *));
	if (!head)
		return (NULL);
	if (!list_size)
	{
		*head = NULL;
		return (head);
	}
	*head = ft_lstnew(args[0]);
	if (!*head)
		return (free(head), NULL);
	node = *head;
	i = 0;
	while (++i < list_size)
	{
		node->next = ft_lstnew(args[i]);
		if (!node->next)
			return (ft_lstclear(head, free), free(head), NULL);
		node = node->next;
	}
	return (head);
}

void	free_all(t_list **stack_a, t_list **stack_b, int **ind, int **tab)
{
	ft_lstclear(stack_a, free);
	free(stack_b);
	free(ind);
	ft_free((void **)tab, -1);
}

void	validate_input(char **av, int **tab)
{
	if (!check_numbers(av) || !check_double(tab) || !check_limits(tab))
	{
		ft_free((void **)tab, -1);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
