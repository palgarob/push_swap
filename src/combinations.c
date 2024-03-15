/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:22:29 by pepaloma          #+#    #+#             */
/*   Updated: 2024/01/12 15:28:36 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add2front(t_stacks stacks)
{
	pa(stacks);
	sa(stacks);
}

void	add2back(t_stacks stacks)
{
	rra(stacks);
	pa(stacks);
	ra(stacks);
	ra(stacks);
}

void	addback(t_stacks stacks)
{
	pa(stacks);
	ra(stacks);
}
