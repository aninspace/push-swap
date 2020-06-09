/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 18:14:30 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/09 13:54:54 by anastasiase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool			swap_a(t_ps *stack)
{
	int			tmp;

	if (stack->a && stack->a->next)
	{
		tmp = stack->a->nb;
		stack->a->nb = stack->a->next->nb;
		stack->a->next->nb = tmp;
		return (true);
	}
	return (false);
}

bool			swap_b(t_ps *stack)
{
	int			tmp;

	if (stack->b && stack->b->next)
	{
		tmp = stack->b->nb;
		stack->b->nb = stack->b->next->nb;
		stack->b->next->nb = tmp;
		return (true);
	}
	return (false);
}

bool			push_a(t_stack **a, t_stack **b)
{
	t_stack		*from_b;
	
	if (*b)
	{
		from_b = take_the_first_element(b);
		put_element_in_the_front(a, from_b);
		return (true);
	}
	return (false);
}

bool			push_b(t_stack **a, t_stack **b)
{
	t_stack		*from_a;

	if (*a)
	{
		from_a = take_the_first_element(a);
		put_element_in_the_front(b, from_a);
		return (true);
	}
	return (false);
}

bool			rotate_a(t_ps *ps)
{
	t_stack		*first;

	// printf("check\n");
	// printf("a && a->next %d %d\n", ps->a->nb, ps->a->next->nb);
	if (ps->a && ps->a->next)
	{
		first = take_the_first_element(&ps->a);
		put_node_in_the_end(&ps->a, first);
		return (true);
	}
	return (false);
}

bool			rotate(t_stack **st)
{
	t_stack		*first;

	// printf("check1\n");
	// printf("a && a->next %d %d\n", (*st)->nb, (*st)->next->nb);
	if (*st && (*st)->next)
	{
		first = take_the_first_element(st);
		put_node_in_the_end(st, first);
		return (true);
	}
	return (false);
}

bool			reverse_rotate(t_stack **st)
{
	t_stack		*last;

	if (*st && (*st)->next)
	{
		last = take_the_last_element(st);
		put_element_in_the_front(st, last);
		return (true);
	}
	return (false);
}