/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_util.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:31:38 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/19 12:41:56 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
** 3 | 2,1 : pb
** 3 | 1,2 : sb pb
** 2 | 3 1 : pb sb
** 2 | 1 3 : sb pb sb 
** 1 | 2 3 : more than 3 step
** 1 | 3 2 : more than 3 step
*/
void	push_to_b2(t_stk **a, t_stk **b, t_var *ps)
{
	int		n1;
	int		n2;
	int		n3;

	n1 = (*a)->i;
	if (list_size(*b) < 3)
		pick_case(a, b, PB, ps);
	else if (list_size(*a) >= 3)
	{
		n2 = (*b)->i;
		n3 = (*b)->nxt->i;
		if (n2 > n1 && n1 > n3)
		{
			pick_case(a, b, RB, ps);
			pick_case(a, b, PB, ps);
			pick_case(a, b, RRB, ps);
		}
		else if (n3 > n1 && n1 > n2)
		{
			pick_case(a, b, SB, ps);
			pick_case(a, b, PB, ps);
			pick_case(a, b, SB, ps);
		}
	}
}

void	push_to_b(t_stk **a, t_stk **b, t_var *ps)
{
	int		n1;
	int		n2;
	int		n3;

	n1 = (*a)->i;
	if (list_size(*b) < 3)
		pick_case(a, b, PB, ps);
	else if (list_size(*a) >= 3)
	{
		n2 = (*b)->i;
		n3 = (*b)->nxt->i;
		if (n1 > n2 && n2 > n3)
			pick_case(a, b, PB, ps);
		else if (n1 > n3 && n3 > n2)
		{
			pick_case(a, b, SB, ps);
			pick_case(a, b, PB, ps);
		}
		else if ((n3 > n2 && n2 > n1) || (n2 > n3 && n3 > n1))
			pick_case(a, b, PB, ps);
		else
			push_to_b2(a, b, ps);
	}
}

void	check_a_top(t_stk **a, t_stk **b, t_var *ps)
{
	t_stk	*tmp;

	tmp = *a;
	if (tmp->nxt && tmp->nxt->nxt)
	{
		if (ashould_move(tmp->nxt->nxt, ps) && !ashould_move(tmp->nxt, ps))
			if (tmp->i == tmp->nxt->nxt->i -2)
				pick_case(a, b, SA, ps);
	}
}
