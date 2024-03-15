/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array2d_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:00:46 by pepaloma          #+#    #+#             */
/*   Updated: 2024/01/10 11:25:19 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_array2d_free(void *param)
{
	char	**array;
	char	**aux;

	array = (char **)param;
	aux = array;
	while (*aux)
		free(*(aux++));
	free(array);
}

void	ft_array2d_free_i(char **array, int i)
{
	while (i--)
		free(array[i]);
	free(array);
}
