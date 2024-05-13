/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:16:49 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/19 12:43:12 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
** 3 | 2,1 : more than 3 step
** 3 | 1,2 : more than 3 step
** 2 | 3 1 : sa pa sa
** 2 | 1 3 : pa sa 
** 1 | 2 3 : pa
** 1 | 3 2 : sa pa
*/
void	push_to_a2(t_stk **a, t_stk **b, t_var *ps)
{
	int		n1;
	int		n2;
	int		n3;

	n1 = (*b)->i;
	if ((*a)->nxt && (*a)->nxt->nxt)
	{
		n2 = (*a)->i;
		n3 = (*a)->nxt->i;
		if (n3 > n1 && n1 > n2)
		{
			pick_case(a, b, PA, ps);
			pick_case(a, b, SA, ps);
		}
		else if (n3 > n2 && n2 > n1)
			pick_case(a, b, PA, ps);
		else if (n2 > n3 && n3 > n1)
		{
			pick_case(a, b, SA, ps);
			pick_case(a, b, PA, ps);
		}
	}
}

void	push_to_a(t_stk **a, t_stk **b, t_var *ps)
{
	int		n1;
	int		n2;
	int		n3;

	n1 = (*b)->i;
	if ((*a)->nxt && (*a)->nxt->nxt)
	{
		n2 = (*a)->i;
		n3 = (*a)->nxt->i;
		if ((n1 > n2 && n2 > n3) || (n1 > n3 && n3 > n2))
			pick_case(a, b, PA, ps);
		else if (n2 > n1 && n1 > n3)
		{
			pick_case(a, b, SA, ps);
			pick_case(a, b, PA, ps);
			pick_case(a, b, SA, ps);
		}
		else
			push_to_a2(a, b, ps);
	}
}
