/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 14:02:31 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/08 16:01:32 by anastasiaseliseva###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*init_new_node(int nb)
{
	t_stack	*st;

	if (!(st = (t_stack *)malloc(sizeof(t_stack))))
		exit(0);
	st->nb = nb;
	st->in = 0;
	st->sort = 1;
	st->next = NULL;
	return (st);
}

