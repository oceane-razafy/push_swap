/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_a_to_stack_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:37:40 by orazafy           #+#    #+#             */
/*   Updated: 2023/02/13 19:49:45 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_midpoint(t_stack *s_stack, int size)
{
	int	*dup;
	int	mid;
	int	i;

	i = 0;
	dup = (int *)malloc(sizeof(int) * size);
	if (dup == NULL)
		return (-1);
	while (i < size)
	{
		dup[i] = s_stack->values[i];
		i++;
	}
	ft_quicksort(dup, 0, size - 1, size);
	mid = dup[size / 2];
	free(dup);
	return (mid);
}

int	ft_chunk_a_conditions(t_stack *s_stack_a)
{
	if (s_stack_a->chunk_size == 0)
		return (1);
	if (ft_check_only_two_small(s_stack_a, s_stack_a->chunk_size)
		&& s_stack_a->chunk_size > 2)
		return (1);
	if (ft_issorted_asc(s_stack_a->values, s_stack_a->chunk_size))
		return (1);
	if (s_stack_a->chunk_size == 1)
		return (1);
	if (s_stack_a->chunk_size == 2
		&& ft_issorted_asc(s_stack_a->values, s_stack_a->chunk_size) == 1)
		return (1);
	if (s_stack_a->chunk_size == 2
		&& ft_issorted_asc(s_stack_a->values, s_stack_a->chunk_size) == 0)
	{
		ft_sa_or_sb(s_stack_a, 1);
		return (1);
	}
	return (0);
}

int	ft_create_chunk_b(t_stack *s_stack_a, t_stack *s_stack_b)
{
	int	i;
	int	init_chunk_size;
	int	nb_ra;

	init_chunk_size = s_stack_a->chunk_size;
	i = 0;
	nb_ra = 0;
	while (s_stack_a->nb_max_to_move > 0
		&& s_stack_a->chunk_size > 2
		&& i != init_chunk_size)
	{	
		if (s_stack_a->values[0] >= s_stack_a->mid)
		{
			ft_ra_or_rb(s_stack_a, 1);
			nb_ra++;
			i++;
		}
		else
		{	
			ft_pb(s_stack_a, s_stack_b);
			i++;
			s_stack_a->nb_max_to_move--;
		}
	}
	return (nb_ra);
}

void	ft_rrotate(t_stack *s_stack, int nb, int rra)
{
	if (nb != 0 && s_stack->chunk_size != s_stack->tmp_size)
	{
		while (nb > 0)
		{
			ft_rra_or_rrb(s_stack, rra);
			nb--;
		}
	}
}

void	ft_stack_a_to_stack_b(t_stack *s_stack_a, t_stack *s_stack_b)
{	
	int	chunk_size;
	int	nb_ra;

	s_stack_b->chunk_size = 0;
	if (ft_chunk_a_conditions(s_stack_a))
		return ;
	s_stack_a->mid = ft_find_midpoint(s_stack_a, s_stack_a->chunk_size);
	if (s_stack_a->mid == -1)
	{
		ft_final_free(s_stack_a, s_stack_b);
		exit(1);
	}
	s_stack_a->nb_max_to_move = s_stack_a->chunk_size / 2;
	nb_ra = ft_create_chunk_b(s_stack_a, s_stack_b);
	ft_rrotate(s_stack_a, nb_ra, 1);
	chunk_size = s_stack_b->chunk_size;
	ft_stack_a_to_stack_b(s_stack_a, s_stack_b);
	s_stack_b->chunk_size = chunk_size;
	ft_stack_b_to_stack_a(s_stack_a, s_stack_b);
}
