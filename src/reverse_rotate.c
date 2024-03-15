/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:33:45 by pepaloma          #+#    #+#             */
/*   Updated: 2024/01/11 13:08:51 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*last2;
	t_list	*aux;

	last2 = ft_lst2ndlast(*stack);
	aux = last2->next;
	last2->next = NULL;
	ft_lstadd_front(stack, aux);
}

void	rra(t_stacks stacks)
{
	reverse_rotate(stacks.a);
	ft_printf("rra\n");
}

void	rrb(t_stacks stacks)
{
	reverse_rotate(stacks.b);
	ft_printf("rrb\n");
}

void	rrr(t_stacks stacks)
{
	reverse_rotate(stacks.a);
	reverse_rotate(stacks.b);
}
