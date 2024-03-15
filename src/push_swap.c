/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:50:21 by pepaloma          #+#    #+#             */
/*   Updated: 2024/02/09 17:52:08 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stacks stacks)
{
	int		aux;
	t_list	*a;

	aux = *(int *)(*stacks.a)->content;
	a = (*stacks.a)->next;
	while (a)
	{
		if (*(int *)a->content <= aux)
			return (0);
		aux = *(int *)a->content;
		a = a->next;
	}
	return (1);
}

/* void	print_stacks(t_stacks stacks)
{
	t_list	*a;
	t_list	*b;

	a = *stacks.a;
	b = *stacks.b;
	while (a || b)
	{
		if (a)
		{
			ft_printf("%d\t", *(int *)a->content);
			a = a->next;
		}
		else
			ft_printf("\t");
		if (b)
		{
			ft_printf("%d\n", *(int *)b->content);
			b = b->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("_\t_\na\tb\n");
} */

void	push_swap(t_stacks stacks)
{
	if (is_sorted(stacks))
		return ;
	else
	{
		if (ft_lstsize(*stacks.a) < 6)
			sort_small(stacks);
		else
			sort_big(stacks);
	}
	if (!is_sorted(stacks))
		ft_printf("KO\n");
}
