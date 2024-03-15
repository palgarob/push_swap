/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array2d_cpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:47:42 by pepaloma          #+#    #+#             */
/*   Updated: 2024/02/09 17:18:39 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_array2d	*ft_array2d_cpy(t_array2d array2d)
{
	t_array2d	*cpy;
	int			i;

	cpy = (t_array2d *)malloc(sizeof(t_array2d));
	if (!cpy)
		return (ft_error_ptr("", 0, 0));
	cpy->size = array2d.size;
	cpy->array = (char **)malloc(sizeof(char *) * (array2d.size.y + 1));
	if (!cpy->array)
		return (ft_error_ptr("", free, cpy));
	i = 0;
	while (i < array2d.size.y)
	{
		cpy->array[i] = (char *)malloc(sizeof(char) * (array2d.size.x + 1));
		if (!cpy->array[i])
		{
			ft_array2d_free_i(cpy->array, i);
			return (ft_error_ptr("", free, cpy));
		}
		ft_strlcpy(cpy->array[i], array2d.array[i], array2d.size.x + 1);
		i++;
	}
	cpy->array[i] = NULL;
	return (cpy);
}
