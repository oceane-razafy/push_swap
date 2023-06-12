/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:19:19 by orazafy           #+#    #+#             */
/*   Updated: 2023/02/07 00:12:31 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_error(t_stack *s_stack_a)
{
	write(2, "Error\n", 6);
	free(s_stack_a->values);
	free(s_stack_a);
	exit(1);
}

long	ft_char_to_int(char *str, t_stack *s_stack_a, int sign)
{
	long	nb;
	int		i;
	int		len;
	long	min;

	len = ft_strlen(str);
	i = 1;
	nb = str[0] % '0';
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] % '0');
		i++;
	}
	if (i < len)
		ft_error(s_stack_a);
	min = (long)INT_MAX + 1;
	if ((nb > min && sign == -1) || (nb > INT_MAX && sign != -1))
		ft_error(s_stack_a);
	return (nb);
}

int	ft_atoi(char *str, t_stack *s_stack_a)
{
	long	sign;
	long	result;

	sign = 1;
	if (*str == 0)
		ft_error(s_stack_a);
	if ((*str < '0' || *str > '9') && (*str != '-') && (*str != '+'))
		ft_error(s_stack_a);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
		if (*str < '0' || *str > '9')
			ft_error(s_stack_a);
	}
	result = sign * ft_char_to_int(str, s_stack_a, sign);
	return (result);
}
