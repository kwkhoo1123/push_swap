/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_case.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:42:42 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/20 20:33:43 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_case(t_stk **a, t_stk **b, int c, t_var *ps)
{
	t_stk	*tmp;

	tmp = NULL;
	if (c == 9)
	{
		pick_case(a, b, SA, ps);
		pick_case(a, b, SB, ps);
	}
	else if (c == 10)
	{
		pick_case(a, b, RA, ps);
		pick_case(a, b, RB, ps);
	}
	else if (c == 11)
	{
		pick_case(a, b, RRA, ps);
		pick_case(a, b, RRB, ps);
	}
}

void	next_next_case(t_stk **a, t_stk **b, int c, t_var *ps)
{
	t_stk	*tmp;

	tmp = NULL;
	if (c == 7 && list_size(*a) > 1)
	{
		ps->log = ft_strjoin(ps->log, "rra\n");
		rr_stk(a, tmp);
	}
	else if (c == 8 && list_size(*b) > 1)
	{
		ps->log = ft_strjoin(ps->log, "rrb\n");
		rr_stk(b, tmp);
		free(tmp);
	}
	else
		double_case(a, b, c, ps);
}

void	next_case(t_stk **a, t_stk **b, int c, t_var *ps)
{
	t_stk	*tmp;

	tmp = NULL;
	if (c == 4)
	{
		ps->log = ft_strjoin(ps->log, "pb\n");
		p_stk(a, b, tmp);
		free(tmp);
	}
	else if (c == 5)
	{
		ps->log = ft_strjoin(ps->log, "ra\n");
		r_stk(a);
		free(tmp);
	}
	else if (c == 6 && list_size(*b) > 1)
	{
		ps->log = ft_strjoin(ps->log, "rb\n");
		r_stk(b);
		free(tmp);
	}
	else
		next_next_case(a, b, c, ps);
}

void	pick_case(t_stk **a, t_stk **b, int c, t_var *ps)
{
	t_stk		*tmp;

	tmp = NULL;
	if (c == 1 && list_size(*a) > 1)
	{
		ps->log = ft_strjoin(ps->log, "sa\n");
		s_stk(a);
	}
	else if (c == 2 && list_size(*b) > 1)
	{
		ps->log = ft_strjoin(ps->log, "sb\n");
		s_stk(b);
	}
	else if (c == 3)
	{
		ps->log = ft_strjoin(ps->log, "pa\n");
		p_stk(b, a, tmp);
		free(tmp);
	}
	else
		next_case(a, b, c, ps);
}
