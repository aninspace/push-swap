/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 19:33:39 by anastasiase       #+#    #+#             */
/*   Updated: 2020/05/31 15:48:10 by anastasiaseliseva###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack			*take_the_first_element(t_stack **stack)
{
	t_stack *tmp;

	if (*stack == NULL)
		return (NULL);
	tmp = *stack;
	if ((*stack)->next == NULL)
		*stack = NULL;
	else
		*stack = tmp->next;
	tmp->next = NULL;
	return (tmp);
}

t_stack			*take_the_last_element(t_stack **stack)
{
	t_stack *pre_last;
	t_stack *tmp;

	pre_last = *stack;
	tmp = *stack;
	if (*stack == NULL)
		return (NULL);
	if ((*stack)->next == NULL)
		*stack = NULL;
	else
	{
		while (pre_last->next && pre_last->next->next)
			pre_last = pre_last->next;
		tmp = pre_last->next;
		pre_last->next = NULL;
	}
	return (tmp);
}

void			put_element_in_the_front(t_stack **stack, t_stack *new)
{
	if (*stack == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}
