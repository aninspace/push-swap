/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:41:18 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/09 11:47:55 by anastasiase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int			count_index_next_after_the_sorted_array(t_ps *ps)
// {
	// 
// }

int			main(int argc, char **argv)
{
	t_ps	*ps;

	ps = parse_and_init_stacks(argc, argv);
	index_stack(ps->a);
	make_the_minimal_sort_of_stack_a(ps);
	if (ps->len_a == 3)
		sort_three_numbers(ps);
	else
		sort_all_other_cases(ps);
	while (ps->a)
	{
		// printf("%d\n", ps->a->nb);
		ps->a = ps->a->next;
	}
	return (0);
}