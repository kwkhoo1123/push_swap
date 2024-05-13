/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_a_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:40:56 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/19 13:08:43 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra_cost(t_stk **a, int pvt, t_var *ps)
{
	t_stk	*tmp;
	int		i;

	tmp = NULL;
	tmp = (*a);
	i = 0;
	while (tmp)
	{
		if (tmp->i < pvt && tmp->i <= ps->len - 3)
			return (i);
		tmp = tmp->nxt;
		i++;
	}
	return (i);
}

int	rra_cost(t_stk **a, int pvt, t_var *ps)
{
	t_stk	*tmp;
	int		i;

	tmp = NULL;
	tmp = ft_lst_last(*a);
	i = 1;
	while (tmp)
	{
		if (tmp->i < pvt && tmp->i <= ps->len - 3)
			return (i);
		tmp = tmp->prv;
		i++;
	}
	return (i);
}

t_stk	*next_rstk(t_stk *a, int pvt)
{
	t_stk	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->i <= pvt)
			return (tmp);
		else
			tmp = tmp->nxt;
	}
	return (NULL);
}

t_stk	*next_rrstk(t_stk *a, int pvt)
{
	t_stk	*tmp;

	tmp = a;
	tmp = ft_lst_last(a);
	while (tmp)
	{
		if (tmp->i <= pvt)
			return (tmp);
		else
			tmp = tmp->prv;
	}
	return (NULL);
}

void	rot_next_a(t_stk **a, t_stk **b, t_var *ps, int pvt)
{
	int		r_c;
	int		rr_c;
	t_stk	*rptr;
	t_stk	*rrptr;

	r_c = ra_cost(a, pvt, ps);
	rr_c = rra_cost(a, pvt, ps);
	rptr = next_rstk(*a, pvt);
	rrptr = next_rrstk(*a, pvt);
	if (r_c <= rr_c || (r_c == rr_c && rptr->i < rrptr->i))
	{
		while (r_c-- > 0 && !check_sort(a))
		{
			pick_case(a, b, RA, ps);
		}
	}
	else if (r_c > rr_c || (r_c == rr_c && rptr->i > rrptr->i))
	{
		while (rr_c-- > 0 && !check_sort(a))
		{
			pick_case(a, b, RRA, ps);
		}
	}
}
