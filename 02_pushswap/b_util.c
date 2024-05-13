/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_util.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:25:43 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/19 13:14:08 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_b_top(t_stk **a, t_stk **b, t_var *ps)
{
	t_stk	*tmp;
	t_stk	*tmp2;

	tmp = *a;
	tmp2 = *b;
	if (tmp2 && tmp->nxt)
	{
		if (tmp->i - tmp2->i <= 2)
		{
			if (ashould_move(tmp, ps))
				pick_case(a, b, PA, ps);
			else if (ashould_move(tmp->nxt, ps) && tmp2->i == tmp->i - 1)
			{
				pick_case(a, b, PA, ps);
				pick_case(a, b, SA, ps);
			}
		}
	}
}

void	rot_max_b(t_stk **a, t_stk **b, t_var *ps, int max)
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
}

void	rot_b(t_stk **a, t_stk **b, int c, t_var *ps)
{
	int		pvt;
	int		mpvt;
	double	seg;

	seg = ps->seg * 2;
	pvt = ft_abs((double)ps->len / (ps->seg / (ps->seg - ps->stg)));
	mpvt = ft_abs((double)ps->len / (seg / (seg - (ps->stg * 2) - 1)));
	if ((*b)->i < mpvt && (*b)->i >= pvt)
	{
		pick_case(a, b, PA, ps);
		pick_case(a, b, RA, ps);
	}
	else
		pick_case(a, b, c, ps);
}

void	rot_max_b_1(t_stk **a, t_stk **b, t_var *ps, int max)
{
	int		idx;
	int		num;

	idx = get_idx((*b), max);
	num = (list_size((*b)) / 2);
	if (num > idx)
		rot_b(a, b, RB, ps);
	else
		rot_b(a, b, RRB, ps);
}
