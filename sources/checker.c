/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 12:16:08 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/09 13:44:17 by anastasiase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_ps	*ps;
	char	*line;
	t_ps	*tmp;

	ps = parse_and_init_stacks(argc, argv);
	// t_ps *tmp = ps;
	// while (tmp->a != NULL)
	// {
	// 	printf("nb %d\n", tmp->a->nb);
	// 	tmp->a = tmp->a->next;
	// }
	tmp = ps;
	while (get_next_line(0, &line) > 0)
	{
		if (check_instruction(line, ps, 1, 0))
			free(line);
		else
		{
			ft_putstr("Error\n");
			exit(EXIT_FAILURE);
		}
	}
	ps = tmp;
	// printf("a->nb %d\n", ps->a->nb);
	// count_len_a(ps);
	// printf("len_a len_arg %d %d\n", ps->len_a, ps->am_arg);
	if (check_ascending_order(ps) && ps->b == NULL)
		printf("OK\n");
	else
		printf("KO\n");
	return (0);
}