/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:01:47 by orazafy           #+#    #+#             */
/*   Updated: 2023/02/15 14:38:36 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	size;
	int	tmp_size;
	int	*values;
	int	mid;
	int	direction;
	int	nb_max_to_move;
	int	chunk_size;
}				t_stack;

int		ft_strlen(char *s);
int		ft_error(t_stack *s_stack_a);
long	ft_char_to_int(char *str, t_stack *s_stack_a, int sign);
int		ft_atoi(char *str, t_stack *s_stack_a);
void	ft_sa_or_sb(t_stack *s_stack, int sa);
void	ft_ra_or_rb(t_stack *s_stack, int ra);
void	ft_rra_or_rrb(t_stack *s_stack, int rra);
void	ft_pb(t_stack *s_stack_a, t_stack *s_stack_b);
void	ft_pa(t_stack *s_stack_a, t_stack *s_stack_b);
void	ft_move_up(t_stack *s_stack);
void	ft_move_down(t_stack *s_stack);
void	ft_swap(int *a, int *b);
int		ft_sort(int *stack, int left, int right, int size_a);
void	ft_quicksort(int *stack, int left, int right, int size_a);
t_stack	*ft_init_stack_b(t_stack *s_stack_a);
void	ft_final_free(t_stack *s_stack_a, t_stack *s_stack_b);
int		ft_check_smaller(int first, int second, t_stack *s_stack_a, int size);
int		ft_check_only_two_small(t_stack *s_stack_a, int size);
void	ft_sort_stack_a(t_stack *s_stack_a);
int		ft_find_midpoint(t_stack *s_stack, int size);
int		ft_chunk_a_conditions(t_stack *s_stack_a);
int		ft_create_chunk_b(t_stack *s_stack_a, t_stack *s_stack_b);
void	ft_rrotate(t_stack *s_stack, int nb, int rra);
void	ft_stack_a_to_stack_b(t_stack *s_stack_a, t_stack *s_stack_b);
int		ft_issorted_des(int *values, int size);
int		ft_check_chunk_already_sorted(t_stack *s_stack_a, t_stack *s_stack_b);
int		ft_chunk_b_conditions(t_stack *s_stack_a, t_stack *s_stack_b);
int		ft_create_chunk_a(t_stack *s_stack_a, t_stack *s_stack_b);
void	ft_stack_b_to_stack_a(t_stack *s_stack_a, t_stack *s_stack_b);
int		ft_check_bigger1(int first, int second, t_stack *s_stack_a, int size);
int		ft_check_bigger2(int first, int second, t_stack *s_stack_a, int size);
void	ft_operations_bigger1(t_stack *s_stack);
int		ft_check_only_two_big(t_stack *s_stack, int size);
void	ft_fill_stack_a(t_stack *s_stack_a, char **argv);
void	ft_check_duplicate(t_stack *s_stack_a);
int		ft_issorted_asc(int *values, int size);

#endif
