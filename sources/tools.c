/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 14:16:12 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/08 20:45:12 by anastasiaseliseva###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack			*get_last_node(t_stack *st)
{
//    t_stack     *tmp;

//    tmp = st;/
	while (st->next)
		st = st->next;
	return (st);
}

bool			check_ascending_order(t_ps *ps)
{
    t_stack		*tmp;

    tmp = ps->a;
	// printf("a->nb %d\n", ps->a->nb);
    while (tmp->next != NULL)
    {
        if (tmp->nb > tmp->next->nb)
            return (false);
        tmp = tmp->next;
    }
    return (true);
}

int            count_len_stack(t_stack *st)
{
	int			len;

	len = 0;
	while (st)
	{
		len++;
		st = st->next;
	}
	return (len);
}

void		index_stack(t_stack *st)
{
	int		i;

	i = 0;
	while (st)
	{
		st->in = i;
		i++;
		st = st->next;
	}
}

int				location_of_index(int len, int index)
{
	return (len / 2 >= index ? index : ((len - index) * -1));
}

int				find_the_sorted_array_in_stack_a(t_ps *ps, t_stack *st)
{
	t_stack *tmp;
	t_stack *first;
	t_stack *sorted;
	int		*ar = (int *)malloc(sizeof(int) * ps->len_a);
	int		i;
	int		k = 0;

	first = st;
	sorted = st;
	i = 0;
	while (st)
	{
		tmp = st;
		i = 0;
		while (i < ps->len_a)
		{
			if (tmp->next == NULL)
			{
				if (first->nb < tmp->nb)
					break ;
			}
			else
			{
				if (tmp->next->nb < tmp->nb)
					break ;
			}
			st->sort++;
			i++;
			if (tmp->next == NULL)
				tmp = first;
			else
				tmp = tmp->next;
		}
		if (st->sort >= sorted->sort)
		{
			if (tmp->in + 1 > ps->len_a - 1)
				ar[k] = 0;
			else
				ar[k] = tmp->in + 1;
			sorted = st;
			k++;
		}
		st = st->next;
	}
	// printf("araay %d\n", ar[k - 1]);
	// printf("k %d\n", k);
	ps->sort = sorted;
	// printf("check %d\n", ps->sort->nb);
	return (ar[k - 1]);
}

int				amount_node_b_to_a(int a, int b, int place)
{
	if (a > 0 && b > 0 && place != -1)
	{
		if (a > b)
			return (a);
		return (b);
	}
	if (a < 0 && b < 0 && place != -1)
	{
		if (abs(a) > abs(b))
			return (abs(a));
		return (abs(b));
	}
	else
		return (abs(a) + abs(b));
}

// void			push_node_in_stack(t_stack *st, int nb)
// {
	// t_stack		*st;
// 
	// st = init_new_node(nb);
	// put_node_in_the_end(st, nb);
// }