/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:06:48 by pepaloma          #+#    #+#             */
/*   Updated: 2024/01/13 19:10:40 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_(t_list *max, t_list **lst, t_list **range0)
{
	while (*lst != max)
		rotate(lst);
	push(lst, range0);
}

static void	set_range(t_list **range0)
{
	t_list	*aux;
	int		i;

	aux = *range0;
	i = 0;
	while (aux)
	{
		*(int *)aux->content = i++;
		aux = aux->next;
	}
}

static void	clear_cpy(t_list **range0)
{
	t_list	*aux;
	t_list	*aux2;

	aux = *range0;
	while (aux)
	{
		aux2 = aux->next;
		free(aux);
		aux = aux2;
	}
}

static void	change_range(t_list **lst)
{
	t_list		*range0;
	t_list		*max;
	t_list		*aux;
	t_list		*cpy;

	cpy = ft_lstcpy(*lst, free);
	range0 = NULL;
	while (cpy)
	{
		aux = cpy;
		max = cpy;
		while (aux)
		{
			if (*(int *)aux->content > *(int *)max->content)
				max = aux;
			aux = aux->next;
		}
		push_(max, &cpy, &range0);
	}
	set_range(&range0);
	clear_cpy(&range0);
}

void	sort_big(t_stacks stacks)
{
	int		i;
	int		j;
	int		stack_size;
	int		bits_size;

	change_range(stacks.a);
	stack_size = ft_lstsize(*stacks.a);
	bits_size = 0;
	while ((stack_size - 1) >> bits_size != 0)
		bits_size++;
	i = 0;
	while (i < bits_size)
	{
		j = 0;
		while (j++ < stack_size)
		{
			if ((*(int *)(*stacks.a)->content >> i) & 1)
				ra(stacks);
			else
				pb(stacks);
		}
		while (ft_lstsize(*stacks.b))
			pa(stacks);
		i++;
	}
}
