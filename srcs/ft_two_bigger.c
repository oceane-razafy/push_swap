/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_two_bigger.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:17:13 by orazafy           #+#    #+#             */
/*   Updated: 2023/02/15 14:19:54 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_bigger1(int first, int second, t_stack *s_stack_a, int size)
{
	int	i;
	int	check1;
	int	check2;

	i = 0;
	check1 = 0;
	check2 = 0;
	while (i < size)
	{
		if (s_stack_a->values[i] > first)
			check1++;
		if (s_stack_a->values[i] > second)
			check2++;
		if (check1 > 0 || check2 > 1)
			break ;
		i++;
	}
	if (check1 > 0 || check2 > 1)
		return (0);
	return (1);
}

int	ft_check_bigger2(int first, int second, t_stack *s_stack_a, int size)
{
	int	i;
	int	check1;
	int	check2;

	i = 0;
	check1 = 0;
	check2 = 0;
	while (i < size)
	{
		if (s_stack_a->values[i] > first)
			check1++;
		if (s_stack_a->values[i] > second)
			check2++;
		if (check1 > 1 || check2 > 0)
			break ;
		i++;
	}
	if (check1 > 1 || check2 > 0)
		return (0);
	return (1);
}

void	ft_operations_bigger1(t_stack *s_stack)
{
	ft_sa_or_sb(s_stack, 1);
	ft_ra_or_rb(s_stack, 1);
	ft_ra_or_rb(s_stack, 1);
}

int	ft_check_only_two_big(t_stack *s_stack, int size)
{
	int	first;
	int	second;

	first = s_stack->values[0];
	second = s_stack->values[1];
	if (ft_issorted_asc(&s_stack->values[2], size - 2) == 0)
		return (0);
	if (first > second)
	{
		if (ft_check_bigger1(first, second, s_stack, size))
		{
			ft_operations_bigger1(s_stack);
			return (1);
		}	
	}
	else
	{
		if (ft_check_bigger2(first, second, s_stack, size))
		{
			ft_ra_or_rb(s_stack, 1);
			ft_ra_or_rb(s_stack, 1);
			return (1);
		}
	}
	return (0);
}
