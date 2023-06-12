/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_b_to_stack_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 02:56:38 by orazafy           #+#    #+#             */
/*   Updated: 2023/02/13 19:50:04 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issorted_des(int *values, int size)
{
	int	i;

	i = 0;
	if (size == 1)
		return (1);
	while (i < size - 1)
	{
		if (values[i] < values[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_chunk_already_sorted(t_stack *s_stack_a, t_stack *s_stack_b)
{
	int	size;
	int	first;
	int	second;

	first = s_stack_b->values[0];
	second = s_stack_b->values[1];
	size = s_stack_b->chunk_size;
	if (ft_check_bigger2(first, second, s_stack_b, size)
		&& ft_issorted_des(&s_stack_b->values[2], size - 2))
		ft_sa_or_sb(s_stack_b, 0);
	if (ft_issorted_des(s_stack_b->values, s_stack_b->chunk_size))
	{
		while (size > 0)
		{
			ft_pa(s_stack_a, s_stack_b);
			size--;
		}
		return (1);
	}
	return (0);
}

int	ft_chunk_b_conditions(t_stack *s_stack_a, t_stack *s_stack_b)
{
	if (s_stack_b->chunk_size == 0)
		return (1);
	if (s_stack_b->chunk_size == 1)
	{
		ft_pa(s_stack_a, s_stack_b);
		return (1);
	}
	if ((s_stack_b->chunk_size == 2)
		&& (ft_issorted_des(s_stack_b->values, s_stack_b->chunk_size) == 1))
	{
		ft_pa(s_stack_a, s_stack_b);
		ft_pa(s_stack_a, s_stack_b);
		return (1);
	}
	if (s_stack_b->chunk_size == 2
		&& ft_issorted_des(s_stack_b->values, s_stack_b->chunk_size) == 0)
	{
		ft_sa_or_sb(s_stack_b, 0);
		ft_pa(s_stack_a, s_stack_b);
		ft_pa(s_stack_a, s_stack_b);
		return (1);
	}
	if (ft_check_chunk_already_sorted(s_stack_a, s_stack_b))
		return (1);
	return (0);
}

int	ft_create_chunk_a(t_stack *s_stack_a, t_stack *s_stack_b)
{
	int	i;
	int	init_chunk_size;
	int	nb_rb;

	init_chunk_size = s_stack_b->chunk_size;
	i = 0;
	nb_rb = 0;
	while (s_stack_b->nb_max_to_move > 0
		&& s_stack_b->chunk_size > 2
		&& i != init_chunk_size)
	{	
		if (s_stack_b->values[0] <= s_stack_b->mid)
		{
			ft_ra_or_rb(s_stack_b, 0);
			nb_rb++;
			i++;
		}
		else
		{	
			ft_pa(s_stack_a, s_stack_b);
			i++;
			s_stack_b->nb_max_to_move--;
		}
	}
	return (nb_rb);
}

void	ft_stack_b_to_stack_a(t_stack *s_stack_a, t_stack *s_stack_b)
{
	int	nb_rb;
	int	next_chunk_size;

	s_stack_a->chunk_size = 0;
	if (ft_chunk_b_conditions(s_stack_a, s_stack_b))
		return ;
	s_stack_b->mid = ft_find_midpoint(s_stack_b, s_stack_b->chunk_size);
	s_stack_b->nb_max_to_move = s_stack_b->chunk_size / 2;
	if (s_stack_b->mid == -1)
	{
		ft_final_free(s_stack_a, s_stack_b);
		exit(1);
	}
	nb_rb = ft_create_chunk_a(s_stack_a, s_stack_b);
	ft_rrotate(s_stack_b, nb_rb, 0);
	next_chunk_size = s_stack_b->chunk_size;
	ft_stack_a_to_stack_b(s_stack_a, s_stack_b);
	s_stack_b->chunk_size = next_chunk_size;
	ft_stack_b_to_stack_a(s_stack_a, s_stack_b);
}
