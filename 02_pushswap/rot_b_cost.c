/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_b_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:25:56 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/19 13:08:51 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rb_cost(t_stk **a, int pvt)
{
	t_stk	*tmp;
	int		i;

	tmp = NULL;
	tmp = (*a);
	i = 0;
	while (tmp)
	{
		if (tmp->i >= pvt)
			return (i);
		tmp = tmp->nxt;
		i++;
	}
	return (i);
}

int	rrb_cost(t_stk **a, int pvt)
{
	t_stk	*tmp;
	int		i;

	tmp = NULL;
	tmp = ft_lst_last(*a);
	i = 1;
	while (tmp)
	{
		if (tmp->i >= pvt)
			return (i);
		tmp = tmp->prv;
		i++;
	}
	return (i);
}

t_stk	*next__rbstk(t_stk *a, int pvt)
{
	t_stk	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->i >= pvt)
			return (tmp);
		else
			tmp = tmp->nxt;
	}
	return (NULL);
}

t_stk	*next_r_rbstk(t_stk *a, int pvt)
{
	t_stk	*tmp;

	tmp = a;
	tmp = ft_lst_last(a);
	while (tmp)
	{
		if (tmp->i >= pvt)
			return (tmp);
		else
			tmp = tmp->prv;
	}
	return (NULL);
}

void	rot_next_b(t_stk **a, t_stk **b, t_var *ps, int pvt)
{
	int		r_c;
	int		rr_c;
	t_stk	*rptr;
	t_stk	*rrptr;

	r_c = rb_cost(b, pvt);
	rr_c = rrb_cost(b, pvt);
	rptr = next__rbstk(*b, pvt);
	rrptr = next_r_rbstk(*b, pvt);
	if (r_c <= rr_c || (r_c == rr_c && rptr->i > rrptr->i))
	{
		while (r_c-- > 0)
		{
			pick_case(a, b, RB, ps);
		}
	}
	else if (r_c > rr_c || (r_c == rr_c && rptr->i < rrptr->i))
	{
		while (rr_c-- > 0)
		{
			pick_case(a, b, RRB, ps);
		}
	}
}
