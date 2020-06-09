/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:52:48 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/09 11:47:45 by anastasiase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			make_the_minimal_sort_of_stack_a(t_ps *ps)
{
	int			in;
	
	ps->len_a = count_len_stack(ps->a);
	in = find_the_sorted_array_in_stack_a(ps, ps->a);
	in = location_of_index(ps->len_a, in);
	// printf("in %d\n", in);
	if (in > 0)
		check_instruction("ra", ps, in, 1);
	else
		check_instruction("rra", ps, in, 1);
}

int			find_place_for_node_in_a(t_stack *st, int nb)
{
	t_stack	*found;
	int		min;

	min = 0;
	while (st)
	{
		if ((min == 0) || (min < 0 && st->nb - nb < 0 &&
			st->nb - nb > min) ||
			(min > 0 && st->nb - nb < min))
		{
			min = st->nb - nb;
			found = st;
		}
		if (st->next == NULL)
			break ;
		st = st->next;
	}
	if (found == st && min < 0)
		return (-1);
	if (min < 0)
		return (found->in + 1);
	else
		return (found->in);
}

int			init_command(t_ps *ps, t_stack *st)
{
	int		cmd;

	ps->tmp_pl = find_place_for_node_in_a(ps->a, st->nb);
	ps->tmp_b = location_of_index(ps->len_b, st->in);
	ps->tmp_a = location_of_index(ps->len_a, ps->tmp_pl);
	cmd = amount_node_b_to_a(ps->tmp_a, ps->tmp_b, ps->tmp_pl);
	return (cmd);
}

void		put_one_node_b_to_a(t_ps *ps)
{
	ps->tmp_b = abs(ps->t_b);
	ps->tmp_a = abs(ps->t_a);
	while (((ps->t_b > 0 && ps->t_a > 0) || (ps->t_b < 0 &&
			ps->t_a < 0)) && ps->tmp_b && ps->tmp_a && ps->pl != -1)
	{
		if (ps->t_b > 0)
			check_instruction("rr", ps, 1, 1);
		else
			check_instruction("rrr", ps, 1, 1);
		ps->tmp_b--;
		ps->tmp_a--;
	}
	if (ps->t_b > 0)
		check_instruction("rb", ps, ps->tmp_b, 1);
	else
		check_instruction("rrb", ps, ps->tmp_b, 1);
	if (ps->pl != -1)
	{
		// printf("place %d\n", ps->pl);
		if (ps->t_a > 0)
			check_instruction("ra", ps, ps->tmp_a, 1);
		else
			check_instruction ("rra", ps, ps->tmp_a, 1);
	}
	check_instruction("pa", ps, 1, 1);
	if (ps->pl == -1)
		check_instruction("ra", ps, 1, 1);
}

void			put_min_number_in_begin(t_ps *ps)
{
	t_stack		*min;
	t_stack		*a;
	int			loc;

	a = ps->a;
	min = a;
	while (a)
	{
		if (a->nb < min->nb)
			min = a;
		a = a->next;
	}
	ps->len_a = count_len_stack(ps->a);
	index_stack(ps->a);
	loc = location_of_index(ps->len_a, min->in);
	if (loc > 0)
		check_instruction("ra", ps, loc, 1);
	else
		check_instruction("rra", ps, loc, 1);
}