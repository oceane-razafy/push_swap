/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:46:28 by orazafy           #+#    #+#             */
/*   Updated: 2023/02/10 02:55:03 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_init_stack_b(t_stack *s_stack_a)
{
	t_stack	*s_stack_b;

	s_stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (s_stack_b == NULL)
	{
		free(s_stack_a->values);
		free(s_stack_a);
		exit (1);
	}	
	s_stack_b->values = (int *)malloc(sizeof(int) * s_stack_a->size);
	if (s_stack_b->values == NULL)
	{
		free(s_stack_a->values);
		free(s_stack_a);
		free(s_stack_b);
		exit (1);
	}
	return (s_stack_b);
}

void	ft_final_free(t_stack *s_stack_a, t_stack *s_stack_b)
{
	free(s_stack_a->values);
	free(s_stack_a);
	free(s_stack_b->values);
	free(s_stack_b);
}

int	ft_check_smaller(int first, int second, t_stack *s_stack_a, int size)
{
	int	i;
	int	check1;
	int	check2;

	i = 0;
	check1 = 0;
	check2 = 0;
	while (i < size)
	{
		if (s_stack_a->values[i] < first)
			check1++;
		if (s_stack_a->values[i] < second)
			check2++;
		if (check1 > 1 || check2 > 0)
			break ;
		i++;
	}
	if (check1 > 1 || check2 > 0)
		return (0);
	return (1);
}

int	ft_check_only_two_small(t_stack *s_stack_a, int size)
{
	int	first;
	int	second;

	first = s_stack_a->values[0];
	second = s_stack_a->values[1];
	if (ft_issorted_asc(&s_stack_a->values[2], size - 2) == 0)
		return (0);
	if (first > second)
	{
		if (ft_check_smaller(first, second, s_stack_a, size))
		{
			ft_sa_or_sb(s_stack_a, 1);
			return (1);
		}	
	}
	return (0);
}

void	ft_sort_stack_a(t_stack *s_stack_a)
{
	t_stack	*s_stack_b;

	if (ft_check_only_two_big(s_stack_a, s_stack_a->size)
		&& s_stack_a->size > 2)
	{
		free(s_stack_a->values);
		free(s_stack_a);
		return ;
	}
	if (ft_check_only_two_small(s_stack_a, s_stack_a->size)
		&& s_stack_a->size > 2)
	{
		free(s_stack_a->values);
		free(s_stack_a);
		return ;
	}
	s_stack_b = ft_init_stack_b(s_stack_a);
	ft_stack_a_to_stack_b(s_stack_a, s_stack_b);
	ft_final_free(s_stack_a, s_stack_b);
}
