/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:52:06 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/20 20:50:56 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_min_small(t_stk **a, t_stk **b, t_var *ps, int min)
{
	int	idx;
	int	num;

	idx = min;
	num = (list_size((*a)) / 2);
	if (num > idx)
		pick_case(a, b, RA, ps);
	else
		pick_case(a, b, RRA, ps);
}

/*
** Push min to other stack until 3 num left
** -rotate until min is on top, direction depend on min's index
** --if min idx < half push up(ra), else push down (rra)
** Do sort 3 then push back into stack A;
*/
void	case_with_10(t_stk **a, t_stk **b, int len, t_var *ps)
{
	int		i;
	int		min;
	t_stk	*tmp1;

	i = len;
	while (i > 3)
	{
		min = get_min(*a);
		tmp1 = (*a)->nxt;
		if ((*a)->i != min && tmp1 && tmp1->i == min)
			pick_case(a, b, SA, ps);
		while (min != (*a)->i)
			rot_min_small(a, b, ps, min);
		if (min == (*a)->i)
		{
			pick_case(a, b, PB, ps);
			i--;
		}
	}
}

void	sort_3_op(t_stk **a, t_stk **b, t_var *ps, int op)
{
	pick_case(a, b, SA, ps);
	pick_case(a, b, op, ps);
}

/*
** case 1: num1 < num2, num3 == min, eg: 231;
** case 2: num1 > num2, num3 == min, eg: 321;
** case 3: num2 == min, eg: 213 / 312;
** casw 4: num1 == min, num2 > num3, eg:132;
*/
void	case_with_3(t_stk **a, t_stk **b, t_var *ps)
{
	t_stk	*tmp;
	int		min;

	tmp = ft_lst_last(*a);
	min = get_min(*a);
	while (check_sort(a) == 0 && list_size(*a) == 3)
	{
		if ((*a)->i < (*a)->nxt->i && tmp->i == min)
			pick_case(a, b, RRA, ps);
		else if ((*a)->i > (*a)->nxt->i && tmp->i == min)
			sort_3_op(a, b, ps, RRA);
		else if ((*a)->nxt->i == min)
		{
			if ((*a)->i < tmp->i)
				pick_case(a, b, SA, ps);
			else if ((*a)->i > tmp->i)
				pick_case(a, b, RA, ps);
		}
		else if ((*a)->i == min && (*a)->nxt->i > tmp->i)
			sort_3_op(a, b, ps, RA);
	}
}

void	sort_small(t_stk **a, t_stk **b, int len, t_var *ps)
{
	if (len == 2 && (*a)->num > (*a)->nxt->num)
		pick_case(a, b, SA, ps);
	if (len <= 3)
		case_with_3(a, b, ps);
	else if (len > 3)
	{
		case_with_10(a, b, len, ps);
		case_with_3(a, b, ps);
		while ((*b))
		{
			pick_case(a, b, PA, ps);
		}
		free_stk(b);
	}
	free_stk(a);
}
