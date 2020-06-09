/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_instruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 12:29:58 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/09 13:54:16 by anastasiase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool			choose_instruction(t_ps *ps, char *line)
{
	bool		ret;
	bool		ret1;

	ret = false;
	ret1 = true;
	if (line[0] == 's' && line[1] == 'a')
		ret = swap_a(ps);
	else if (line[0] == 's' && line[1] == 'b')
		ret = swap_b(ps);
	else if (line[0] == 's' && line[1] == 's')
	{
		ret = swap_a(ps);
		ret1 = swap_b(ps);
	}
	else if (line[0] == 'p' && line[1] == 'b')
		ret = push_b(&ps->a, &ps->b);
	else if (line[0] == 'p' && line[1] == 'a')
		ret = push_a(&ps->a, &ps->b);
	else if (line[0] == 'r' && line[1] == 'a')
	{
		ret = rotate(&ps->a);
	}
	else if (line[0] == 'r' && line[1] == 'b')
	{
		ret = rotate(&ps->b);
	}
	else if (line[0] == 'r' && line[1] == 'r' && ft_strlen(line) == 2)
	{
		ret = rotate(&ps->a);
		ret1 = rotate(&ps->b);
	}
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
		ret = reverse_rotate(&ps->a);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
		ret = reverse_rotate(&ps->b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
	{
		ret = reverse_rotate(&ps->a);
		reverse_rotate(&ps->b);
	}
	if (ret == true && ret1 == true)
	{
		return (true);
	}
	else
	{
		// printf("hello\n");
		return (false);
	}
}

bool		check_instruction(char *line, t_ps *ps, int count, int fl)
{
	count = abs(count);
	
	while (count > 0)
	{
		if (choose_instruction(ps, line))
		{
			if (fl == 1)
				printf("%s\n", line);
		}
		else
		{
			return (false);
		}
		count--;
	}
	return (true);
}