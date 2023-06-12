/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_up_or_down.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 02:47:37 by orazafy           #+#    #+#             */
/*   Updated: 2023/02/09 02:49:34 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_stack *s_stack_a, t_stack *s_stack_b)
{
	int	nb_to_move;

	s_stack_b->tmp_size = s_stack_a->size - s_stack_a->tmp_size;
	nb_to_move = s_stack_a->values[0];
	ft_move_up(s_stack_a);
	ft_move_down(s_stack_b);
	s_stack_b->values[0] = nb_to_move;
	s_stack_b->chunk_size++;
	s_stack_a->chunk_size--;
	write(1, "pb\n", 3);
}

void	ft_pa(t_stack *s_stack_a, t_stack *s_stack_b)
{
	int	nb_to_move;

	s_stack_b->tmp_size = s_stack_a->size - s_stack_a->tmp_size;
	nb_to_move = s_stack_b->values[0];
	ft_move_up(s_stack_b);
	ft_move_down(s_stack_a);
	s_stack_a->values[0] = nb_to_move;
	s_stack_b->chunk_size--;
	s_stack_a->chunk_size++;
	write(1, "pa\n", 3);
}

void	ft_move_up(t_stack *s_stack)
{
	int	i;

	i = 0;
	while (i < s_stack->tmp_size - 1)
	{
		s_stack->values[i] = s_stack->values[i + 1];
		i++;
	}
	s_stack->tmp_size--;
}

void	ft_move_down(t_stack *s_stack)
{
	int	i;

	s_stack->tmp_size++;
	i = s_stack->tmp_size - 1;
	while (i > 0)
	{
		s_stack->values[i] = s_stack->values[i - 1];
		i--;
	}
}
