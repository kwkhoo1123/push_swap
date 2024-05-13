/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:54:06 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/19 15:24:16 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fix_size_sort(t_stk **a, t_stk **b, t_var *ps)
{
	double	pvt;

	while (ps->stg <= ps->seg)
	{
		pvt = ft_abs((double)ps->len / (ps->seg / (ps->stg)));
		while (has_below((*a), pvt) && list_size(*a) > 5 && !check_sort(a))
		{
			while ((*a)->i < pvt && !check_sort(a) && ps->len - (*a)->i >= 5)
				pick_case(a, b, PB, ps);
			rot_next_a(a, b, ps, pvt);
		}
		ps->stg++;
	}
	case_with_10(a, b, list_size(*a), ps);
	case_with_3(a, b, ps);
	ps->stg = 1;
}

int	rot_a(t_stk **a, t_stk **b, int dir, t_var *ps)
{
	if (dir > 0)
	{
		pick_case(a, b, RA, ps);
		return (1);
	}
	else if (dir < 0)
	{
		pick_case(a, b, RRA, ps);
		return (-1);
	}
	else
		return (0);
}

void	init_sort(t_stk **a, t_stk **b, t_var *ps)
{
	double	pvt;
	int		r_c;

	r_c = 0;
	pvt = ft_abs((double)ps->len / (ps->seg / (ps->seg - ps->stg)));
	while (list_size(*a) > 3 && !check_sort(a))
	{
		while (ps->len - (*a)->i <= 2 && list_size(*a) > 3)
			r_c += rot_a(a, b, 1, ps);
		if (r_c >= 3 && (ps->len - (*a)->i - r_c) == 0)
			r_c += rot_a(a, b, 1, ps);
		else
			pick_case(a, b, PB, ps);
		while ((list_size(*a) == r_c && list_size(*a) > 3) && !check_sort(a))
		{
			r_c += rot_a(a, b, -1, ps);
			if (!check_sort(a))
				pick_case(a, b, PB, ps);
		}
	}
	case_with_3(a, b, ps);
	ps->stg = 1;
}

void	sort_big(t_stk **a, t_stk **b, t_var *ps)
{
	init_median_sort(a, b, ps);
	while (!check_sort(a) || list_size(*a) < ps->len)
	{
		b_to_a(a, b, ps);
		next_median_sort(a, b, ps);
	}
}
