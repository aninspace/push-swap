/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 16:18:20 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/08 21:08:32 by anastasiase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			sort_three_numbers(t_ps *ps)
{
	if (!(check_ascending_order(ps)))
		check_instruction("sa", ps, 1, 1);
}

void			put_b_in_a(t_ps *ps)
{
	t_stack		*tmp_b;
	int			opt_cmd;
	int			cmd;

	while (ps->b)
	{
		tmp_b = ps->b;
		index_stack(ps->a);
		index_stack(ps->b);
		ps->len_a = count_len_stack(ps->a);
		ps->len_b = count_len_stack(ps->b);
		opt_cmd = init_command(ps, tmp_b);
		ps->t_a = ps->tmp_a;
		ps->t_b = ps->tmp_b;
		ps->pl = ps->tmp_pl;
		while (tmp_b)
		{
			cmd = init_command(ps, tmp_b);
			if (opt_cmd > cmd)
			{
				opt_cmd = cmd;
				ps->t_a = ps->tmp_a;
				ps->t_b = ps->tmp_b;
				ps->pl = ps->tmp_pl;
			}
			tmp_b = tmp_b->next;
		}
		put_one_node_b_to_a(ps);
	}
}

// void			put_a_in_b(t_ps *ps)
// {
// 	t_stack		*st;

	
// }

void			sort_all_other_cases(t_ps *ps)
{
	t_stack		*tmp_a;

	tmp_a = ps->a;
	while (tmp_a && tmp_a->in != ps->sort->in)
	{
		// printf("tmp_a %d\n", tmp_a->in);
		// printf("tmp_a %d\n", tmp_a->next->in);
		// printf("sort %d\n", ps->sort->in);
		tmp_a = tmp_a->next;
		check_instruction("pb", ps, 1, 1);
	}
	put_b_in_a(ps);
	put_min_number_in_begin(ps);
}