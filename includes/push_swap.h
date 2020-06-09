/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 18:14:47 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/09 13:32:59 by anastasiase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include <math.h>
# include <limits.h>

typedef struct		s_stack
{
	int				nb;
	int				in;
	int				sort;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_ps
{
	t_stack			*a;
	t_stack			*b;
	t_stack			*sort;
	int				am_arg;
	int				len_a;
	int				len_b;
	int				tmp_pl;
	int				tmp_b;
	int				tmp_a;
	int				pl;
	int				t_a;
	int				t_b;
}					t_ps;

t_ps				*parse_and_init_stacks(int argc, char **argv);
t_stack				*get_last_node(t_stack *st);
t_stack				*init_new_node(int nb);
// void			    put_node_in_the_end(t_stack *a, t_stack *new);
void				init_stack_a(t_ps *ps, int argc, char **argv);
bool				check_duplicate(t_stack *a, int nb);
t_stack				*take_the_first_element(t_stack **stack);
void				put_element_in_the_front(t_stack **stack, t_stack *new);
void				put_node_in_the_end(t_stack **st, t_stack *new);
t_stack				*take_the_last_element(t_stack **stack);
bool				swap_a(t_ps *stack);
bool				swap_b(t_ps *stack);
bool				push_a(t_stack **a, t_stack **b);
bool				push_b(t_stack **a, t_stack **b);
bool				rotate(t_stack **st);
bool				reverse_rotate(t_stack **st);
bool				check_instruction(char *line, t_ps *ps, int count, int fl);
bool				check_ascending_order(t_ps *ps);
bool				rotate_a(t_ps *ps);
int					count_len_stack(t_stack *st);
void				index_stack(t_stack *st);
int					find_the_sorted_array_in_stack_a(t_ps *ps, t_stack *st);
void				make_the_minimal_sort_of_stack_a(t_ps *ps);
int					location_of_index(int len, int index);
void				sort_three_numbers(t_ps *ps);
int					amount_node_b_to_a(int a, int b, int place);
int					init_command(t_ps *ps, t_stack *st);
void				put_one_node_b_to_a(t_ps *ps);
void				put_min_number_in_begin(t_ps *ps);
void				sort_all_other_cases(t_ps *ps);

#endif