/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:46:22 by orazafy           #+#    #+#             */
/*   Updated: 2023/02/09 02:28:52 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_stack_a(t_stack *s_stack_a, char **argv)
{
	int	i;

	i = 0;
	while (i < s_stack_a->size)
	{
		s_stack_a->values[i] = ft_atoi(argv[i + 1], s_stack_a);
		i++;
	}
	ft_check_duplicate(s_stack_a);
}

void	ft_check_duplicate(t_stack *s_stack_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < (s_stack_a->size - 1))
	{
		j = i + 1;
		while (j < s_stack_a->size)
		{
			if (s_stack_a->values[i] == s_stack_a->values[j])
				ft_error(s_stack_a);
			j++;
		}
	i++;
	}
}

int	ft_issorted_asc(int *values, int size)
{
	int	i;

	i = 0;
	if (size == 1)
		return (1);
	while (i < size - 1)
	{
		if (values[i] > values[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char	**argv)
{
	t_stack	*s_stack_a;

	s_stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (s_stack_a == NULL)
		return (0);
	if (argc == 1)
		return (0);
	s_stack_a->size = argc - 1;
	s_stack_a->tmp_size = argc - 1;
	s_stack_a->chunk_size = argc - 1;
	s_stack_a->values = (int *)malloc(sizeof(int) * s_stack_a->size);
	if (s_stack_a->values == NULL)
	{
		free(s_stack_a);
		return (0);
	}
	ft_fill_stack_a(s_stack_a, argv);
	if (ft_issorted_asc(s_stack_a->values, s_stack_a->size) == 1)
	{
		free(s_stack_a->values);
		free(s_stack_a);
		return (0);
	}
	ft_sort_stack_a(s_stack_a);
	return (0);
}
