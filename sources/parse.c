/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 12:37:39 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/09 13:43:13 by anastasiase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			put_node_in_the_end(t_stack **st, t_stack *new)
{
	t_stack		*last;

	if ((*st) == NULL)
	{
        (*st) = new;
        return ;
    }
	last = get_last_node(*st);
	last->next = new;
}

bool			check_duplicate(t_stack *a, int nb)
{
	while (a)
	{
		if (a->nb == nb)
			return (false);
		a = a->next;
	}
	return (true);
}

void			init_stack_a(t_ps *ps, int argc, char **argv)
{
	int			i;
	int			nb;
	t_stack		*new;

	i = 1;
	if (argc == 1)
		exit(EXIT_FAILURE);
	if (argc == 2)
	{
		// printf("%s\n", argv[1]);
		argv = ft_strsplit(argv[1], ' ');
		i = 0;
	}
	while (argv[i])
	{
		if (ft_atoi(argv[i]) >= INT_MAX)
		{
			ft_putstr("Error\n");
			exit(EXIT_FAILURE);
		}
		if (ft_is_number(argv[i]))
			nb = ft_atoi(argv[i]);
		if (!ft_is_number(argv[i]) || !check_duplicate(ps->a, nb))
		{
			ft_putstr("ERROR\n");
			exit(EXIT_FAILURE);
		}
		new = init_new_node(nb);
		put_node_in_the_end(&ps->a, new);
		i++;
	}
}

t_ps			*parse_and_init_stacks(int argc, char **argv)
{
	t_ps		*ps;
	if (!(ps = (t_ps *)malloc(sizeof(t_ps))))
		exit(0);
	ps->a = NULL;
	ps->b = NULL;
	ps->sort = NULL;
	init_stack_a(ps, argc, argv);
	return (ps);
}