/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:25:21 by pepaloma          #+#    #+#             */
/*   Updated: 2024/01/11 13:09:02 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*aux;
	t_list	*aux2;

	aux = *stack;
	aux2 = (*stack)->next->next;
	*stack = (*stack)->next;
	(*stack)->next = aux;
	aux->next = aux2;
}

void	sa(t_stacks stacks)
{
	swap(stacks.a);
	ft_printf("sa\n");
}

void	sb(t_stacks stacks)
{
	swap(stacks.b);
	ft_printf("sb\n");
}

void	ss(t_stacks stacks)
{
	sa(stacks);
	sb(stacks);
}
