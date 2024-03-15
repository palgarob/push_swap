/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:43:44 by pepaloma          #+#    #+#             */
/*   Updated: 2024/02/13 13:11:52 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_list(void *param)
{
	t_list	**a;

	a = (t_list **)param;
	ft_lstclear(a, free);
}

static int	check_duplicate(t_list **a, int *n)
{
	t_list	*aux;

	aux = *a;
	while (aux)
	{
		if (*(int *)(aux->content) == *n)
			return (1);
		aux = aux->next;
	}
	return (0);
}

static int	converse_integers(char **ints_strings, t_list **a)
{
	int		i;
	int		*aux_int;
	t_list	*aux_list;

	i = 0;
	while (ints_strings[i])
	{
		aux_int = (int *)malloc(sizeof(int));
		if (!aux_int)
			return (ft_error(ERROR_MALLOC, clear_list, a, 1));
		if (ft_atoi_of(ints_strings[i], aux_int))
			return (free(aux_int), ft_error("Error\n", clear_list, a, 1));
		if (check_duplicate(a, aux_int))
			return (free(aux_int), ft_error("Error\n", clear_list, a, 1));
		aux_list = ft_lstnew(aux_int);
		if (!aux_list)
		{
			ft_lstclear(a, free);
			return (free(aux_int), 1);
		}
		ft_lstadd_back(a, aux_list);
		i++;
	}
	return (0);
}

static void	parse_args(int argc, char **argv, t_list **a)
{
	char	**ints_strings;
	int		there_was_a_malloc;

	if (argc == 1)
		exit(1);
	there_was_a_malloc = 0;
	if (argc == 2)
	{
		ints_strings = ft_split(argv[1], ' ');
		if (!ints_strings)
			exit(1);
		there_was_a_malloc = 1;
	}
	else
		ints_strings = &argv[1];
	if (converse_integers(ints_strings, a))
	{
		if (there_was_a_malloc)
			ft_array2d_free(ints_strings);
		exit(1);
	}
	if (there_was_a_malloc)
		ft_array2d_free(ints_strings);
}

int	main(int argc, char *argv[])
{
	t_list		*a;
	t_list		*b;
	t_stacks	stacks;

	a = NULL;
	b = NULL;
	parse_args(argc, argv, &a);
	stacks.a = &a;
	stacks.b = &b;
	push_swap(stacks);
	ft_lstclear(&a, free);
	return (0);
}
