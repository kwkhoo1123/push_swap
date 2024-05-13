/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 01:24:17 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/26 14:52:09 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	median_sort(t_stk **a, t_stk **b, t_var *ps)
{
	int		pvt;
	double	min;
	double	max;

	ps->stg = get_max_power(*a, ps);
	while (!check_sort(a))
	{
		ps->stg++;
		min = get_min(*a);
		max = highest_unsortable(*a, ps);
		pvt = ft_abs((max + min) / 2);
		pvt = get_med(a, ps);
		if (max - min <= 3)
			pvt = max + 1;
		while (has_below((*a), pvt))
		{
			if ((*a)->i < pvt)
			{
				pick_case(a, b, PB, ps);
				(*b)->g = ps->stg;
			}
			else
				rot_next_a(a, b, ps, pvt);
		}
	}
}

void	below_4_a(t_stk **a, t_stk **b, t_var *ps)
{
	int		pow;
	int		min;

	pow = get_max_power(*a, ps);
	while (group_size_a(*a, pow, ps) > 0)
	{
		min = get_min(*a);
		while (min != (*a)->i)
			rot_min_small(a, b, ps, min);
		push_to_b(a, b, ps);
	}
}

void	init_median_sort(t_stk **a, t_stk **b, t_var *ps)
{
	int		pvt;
	int		pow;
	double	div;

	pow = get_min_power(*a, ps);
	while (list_size(*a) > 3 && !check_sort(a) && pow < ps->pow)
	{
		pow++;
		div = ft_power(2, pow);
		pvt = ft_abs((double)ps->len / (div / (div - 1)));
		while (has_below((*a), pvt))
		{
			if ((*a)->i < pvt)
			{
				pick_case(a, b, PB, ps);
				(*b)->g = pow;
			}
			else
				rot_next_a(a, b, ps, pvt);
		}
	}
	case_with_3(a, b, ps);
}

void	next_median_sort(t_stk **a, t_stk **b, t_var *ps)
{
	int		gsize;

	ps->stg = get_max_power(*a, ps);
	gsize = group_size_a(*a, ps->stg, ps);
	if (!check_sort(a))
	{
		if (gsize <= 8)
			below_4_a(a, b, ps);
		else
		{
			while (!check_sort(a) && gsize > 4)
			{
				median_sort(a, b, ps);
				gsize = group_size_a(*a, ps->stg, ps);
			}
		}
	}
}
