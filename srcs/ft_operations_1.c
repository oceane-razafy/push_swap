/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:15:33 by orazafy           #+#    #+#             */
/*   Updated: 2023/02/09 02:30:10 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_or_sb(t_stack *s_stack, int sa)
{
	ft_swap(&s_stack->values[0], &s_stack->values[1]);
	if (sa)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	ft_ra_or_rb(t_stack *s_stack, int ra)
{
	int	i;
	int	tmp_last;

	i = 0;
	while (i < s_stack->tmp_size - 1)
	{
		if (i == 0)
		{
			tmp_last = s_stack->values[s_stack->tmp_size - 1];
			s_stack->values[s_stack->tmp_size - 1] = s_stack->values[0];
			s_stack->values[0] = s_stack->values[1];
		}
		else if (i == s_stack->tmp_size - 2)
			s_stack->values[i] = tmp_last;
		else
			s_stack->values[i] = s_stack->values[i + 1];
		i++;
	}
	if (ra)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	ft_rra_or_rrb(t_stack *s_stack, int rra)
{
	int	i;
	int	tmp_first;
	int	tmp_size;

	tmp_size = s_stack->tmp_size;
	i = tmp_size - 1;
	while (i > 0)
	{
		if (i == tmp_size - 1)
		{
			tmp_first = s_stack->values[0];
			s_stack->values[0] = s_stack->values[tmp_size - 1];
			s_stack->values[tmp_size - 1] = s_stack->values[tmp_size - 2];
		}
		else if (i == 1)
			s_stack->values[i] = tmp_first;
		else
			s_stack->values[i] = s_stack->values[i - 1];
		i--;
	}
	if (rra)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}
