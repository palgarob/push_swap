/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:50:24 by pepaloma          #+#    #+#             */
/*   Updated: 2024/02/09 17:52:33 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/src/libft.h"

typedef struct s_stacks
{
	t_list	**a;
	t_list	**b;
}	t_stacks;

void	push_swap(t_stacks stacks);
void	sort_small(t_stacks stacks);
void	sort_big(t_stacks stacks);

void	rotate(t_list **stack);
void	push(t_list **stack_src, t_list **stack_dst);

void	sa(t_stacks stacks);
void	sb(t_stacks stacks);
void	ss(t_stacks stacks);
void	pa(t_stacks stacks);
void	pb(t_stacks stacks);
void	rra(t_stacks stacks);
void	rrb(t_stacks stacks);
void	rrr(t_stacks stacks);
void	ra(t_stacks stacks);
void	rb(t_stacks stacks);
void	rr(t_stacks stacks);

void	add2front(t_stacks stacks);
void	add2back(t_stacks stacks);
void	addback(t_stacks stacks);

//void	print_stacks(t_stacks stacks)

#endif
