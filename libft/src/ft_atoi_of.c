/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_of.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:29:19 by pepaloma          #+#    #+#             */
/*   Updated: 2024/02/09 18:16:19 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_spaces(char *s)
{
	int	i;

	i = 0;
	while (*s == ' ' || *s == '\t' || *s == '\v'
		|| *s == '\f' || *s == '\r' || *s == '\n')
	{
		i++;
		s++;
	}
	return (i);
}

static int	check_overflow(long aux, int *n)
{
	if (aux > INT_MAX || aux < INT_MIN)
		return (1);
	else
	{
		*n = aux;
		return (0);
	}
}

long	convert_to_long(char *str)
{
	long	l;

	l = 0;
	while (ft_isdigit(*str))
	{
		l = l * 10 + (*str - '0');
		str++;
	}
	return (l);
}

int	ft_atoi_of(char *str, int *n)
{
	long	aux;

	str += count_spaces(str);
	if (*str == '-')
		aux = convert_to_long(str + 1) * -1;
	else if (*str == '+')
		aux = convert_to_long(str + 1);
	else if (ft_isdigit(*str))
		aux = convert_to_long(str);
	else
		return (1);
	return (check_overflow(aux, n));
}

/* int	main(void)
{
	char	*str = "-21472648";
	int		n;

	if (ft_atoi_of(str, &n))
		printf("INVALID\n");
	else
		printf("%d\n", n);
	
} */
