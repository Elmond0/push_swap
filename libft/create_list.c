/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:28:39 by miricci           #+#    #+#             */
/*   Updated: 2025/03/16 15:41:05 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
t_list	**create_list(int list_size, char **nptr)
{
	t_list	**list;
	t_list	*node;
	int		i;
	int		*arg;
	
	i = 0;
	list = NULL;
	arg = malloc(sizeof(int));
	if (!arg)
	return (0);
	while (i < list_size)
	{
		*arg = ft_atoi(nptr[i]);
		node = ft_lstnew(arg);
		if (!node)
		{
			ft_lstiter(*list, free);
			return (NULL);
		}
		ft_lstadd_back(list, node);
		i++;
	}
	return (list);
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
	*/
