/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:28:35 by pepaloma          #+#    #+#             */
/*   Updated: 2024/01/12 21:14:17 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_src, t_list **stack_dst)
{
	t_list	*aux;

	aux = (*stack_src)->next;
	ft_lstadd_front(stack_dst, *stack_src);
	*stack_src = aux;
}

void	pa(t_stacks stacks)
{
	push(stacks.b, stacks.a);
	ft_printf("pa\n");
}

void	pb(t_stacks stacks)
{
	push(stacks.a, stacks.b);
	ft_printf("pb\n");
}
