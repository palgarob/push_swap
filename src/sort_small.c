/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:11:36 by pepaloma          #+#    #+#             */
/*   Updated: 2024/01/13 19:09:12 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_distance(t_stacks stacks)
{
	int		i;
	int		aux_int;
	t_list	*aux_list;

	aux_list = *stacks.a;
	aux_int = *(int *)(*stacks.b)->content;
	i = 0;
	while (aux_list && aux_int > *(int *)aux_list->content)
	{
		i++;
		aux_list = aux_list->next;
	}
	return (i);
}

static void	sort3(t_stacks stacks)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*stacks.a)->content;
	second = *(int *)(*stacks.a)->next->content;
	third = *(int *)(*stacks.a)->next->next->content;
	if (first < second && second < third & first < third)
		return ;
	else if (first > second && first > third && second < third)
		ra(stacks);
	else if (first < second && first > third && second > third)
		rra(stacks);
	else
	{
		sa(stacks);
		sort3(stacks);
	}
}

void static	sort4(t_stacks stacks)
{
	pb(stacks);
	sort3(stacks);
	if (calculate_distance(stacks) == 0)
		pa(stacks);
	else if (calculate_distance(stacks) == 1)
		add2front(stacks);
	else if (calculate_distance(stacks) == 2)
		add2back(stacks);
	else if (calculate_distance(stacks) == 3)
		addback(stacks);
}

static void	sort5(t_stacks stacks)
{
	pb(stacks);
	sort4(stacks);
	if (calculate_distance(stacks) == 0)
		pa(stacks);
	else if (calculate_distance(stacks) == 1)
		add2front(stacks);
	else if (calculate_distance(stacks) == 2)
	{
		ra(stacks);
		ra(stacks);
		pa(stacks);
		rra(stacks);
		rra(stacks);
	}
	else if (calculate_distance(stacks) == 3)
		add2back(stacks);
	else if (calculate_distance(stacks) == 4)
		addback(stacks);
}

void	sort_small(t_stacks stacks)
{
	if (ft_lstsize(*stacks.a) == 2)
		sa(stacks);
	else if (ft_lstsize(*stacks.a) == 3)
		sort3(stacks);
	else if (ft_lstsize(*stacks.a) == 4)
		sort4(stacks);
	else
		sort5(stacks);
}
