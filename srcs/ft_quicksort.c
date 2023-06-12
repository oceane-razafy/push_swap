/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 03:31:37 by orazafy           #+#    #+#             */
/*   Updated: 2023/02/09 03:31:39 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_sort(int *stack, int left, int right, int size_a)
{
	int	i;
	int	j;

	i = left + 1;
	j = right;
	while (i <= j)
	{
		while (stack[i] <= stack[left])
		{
			i++;
			if (i == size_a)
				break ;
		}
		while (stack[j] > stack[left])
		{
			j--;
			if (j == -1)
				break ;
		}
		if (i < j)
			ft_swap(&stack[i], &stack[j]);
	}
	if (stack[j] < stack[left] && j != -1)
		ft_swap(&stack[j], &stack[left]);
	return (j);
}

void	ft_quicksort(int *stack, int left, int right, int size_a)
{
	int	mid;

	if (left < right)
	{
		mid = ft_sort(stack, left, right, size_a);
		ft_quicksort(stack, left, mid - 1, size_a);
		ft_quicksort(stack, mid + 1, right, size_a);
	}
}
