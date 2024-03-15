/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:31:09 by pepaloma          #+#    #+#             */
/*   Updated: 2024/01/12 21:09:36 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*aux;

	aux = *stack;
	*stack = (*stack)->next;
	aux->next = NULL;
	ft_lstadd_back(stack, aux);
}

void	ra(t_stacks stacks)
{
	rotate(stacks.a);
	ft_printf("ra\n");
}

void	rb(t_stacks stacks)
{
	rotate(stacks.b);
	ft_printf("rb\n");
}

void	rr(t_stacks stacks)
{
	rotate(stacks.a);
	rotate(stacks.b);
}
