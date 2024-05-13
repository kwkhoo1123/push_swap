/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_b_directsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:25:43 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/19 13:13:55 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	r_next_cost(t_stk **stk, int dir, t_var *ps)
{
	t_stk	*tmp;
	int		cost;
	int		pvt;

	tmp = stk;
	pvt = ps->len / (ps->seg / (ps->seg - ps->stg));
	
} */

/* void	rot_max_b(t_stk **a, t_stk **b, t_var *ps, int max)
{
	int		idx;
	int		num;
	t_stk	*tmp;

	tmp = NULL;
	tmp = ft_lst_last(*a);
	idx = get_idx((*b), max);
	num = (list_size((*b)) / 2);
	if (num > idx)
		pick_case(a, b, RB, ps);
	else
		pick_case(a, b, RRB, ps);
	if ((*b)->i == (*a)->i - 2 && tmp->i == ps->len)
	{
		pick_case(a, b, PA, ps);
		pick_case(a, b, RA, ps);
	}
} */
/* 
void	sort_b(t_stk **a, t_stk **b, t_var *ps)
{
	int		max;
	t_stk	*tmp;

	tmp = NULL;
	while ((*b))
	{
		max = get_max(*b);
		while (max != (*b)->num)
			rot_max_b(a, b, ps, max);
		tmp = ft_lst_last(*a);
		if (max == (*b)->num)
		{
			pick_case(a, b, PA, ps);
			if (tmp->i == (*a)->i - 1)
				pick_case(a, b, RRA, ps);
		}
	}
}
 */

/* 3 step sort loop
void	sort_big_3(t_stk **a, t_stk **b, t_var *ps)
{
	int		pvt;
	int		mpvt;
	int		max;
	double	seg;

	seg = ps->seg * 2;
	pvt = ft_abs((double)ps->len / (ps->seg / (ps->seg - ps->stg)));
	mpvt = ft_abs((double)ps->len / (seg / (seg - (ps->stg * 2) - 1)));
	while (has_above(*b, pvt))
	{
		max = get_max(*b);
		while (max != (*b)->num)
			rot_max_b(a, b, ps, max);
		if (max == (*b)->num)
			pick_case(a, b, PA, ps);
	}
	ps->stg += 1;
}

void	sort_big_2(t_stk **a, t_stk **b, t_var *ps)
{
	t_stk	*tmp;
	int		next;

	tmp = NULL;
	tmp = ft_lst_last(*a);
	next = highest_unsortable(*a, ps);
	while (tmp->i != ps->len)
	{
		pick_case(a, b, RRA, ps);
		tmp = ft_lst_last(*a);
	}
	while (!ashould_move(*a, ps))
	{
		if ((*a)->i != next)
			push_to_b(a, b, ps);
		else if ((*a)->i == next && (tmp->i == ps->len))
			pick_case(a, b, RA, ps);
	}
	tmp = ft_lst_last(*a);
	if (tmp->i != ps->len)
		pick_case(a, b, RRA, ps);
}

void	sort_big_1(t_stk **a, t_stk **b, t_var *ps)
{
	int		pvt;
	int		mpvt;
	int		max;
	double	seg;

	seg = ps->seg * 2;
	pvt = ft_abs((double)ps->len / (ps->seg / (ps->seg - ps->stg)));
	mpvt = ft_abs((double)ps->len / (seg / (seg - (ps->stg * 2) - 1)));
	while (has_above(*b, mpvt))
	{
		max = get_max(*b);
		while (max != (*b)->num)
			rot_max_b_1(a, b, ps, max);
		if (max == (*b)->num)
			pick_case(a, b, PA, ps);
	}
}
 */