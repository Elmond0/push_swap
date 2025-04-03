/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:28:50 by miricci           #+#    #+#             */
/*   Updated: 2025/03/16 22:33:49 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_list(t_list **head)
{
	t_list	*node;
	int		i;

	i = 1;
	node = *head;
	ft_printf("\n------------PRINT LIST---------------\n");
	while (node)
	{
		ft_printf("node %d: \n", i);
		ft_printf("next: %p\n", node->next);
		node = node->next;
		i++;
	}
	ft_printf("------------PRINT LIST---------------\n\n");
}
