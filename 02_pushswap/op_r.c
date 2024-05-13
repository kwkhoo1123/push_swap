/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:32:21 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/19 13:02:46 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk	*rr_swap(t_stk *top, t_stk *tmp)
{
	while (top->nxt)
		top = top->nxt;
	tmp->num = top->num;
	tmp->i = top->i;
	tmp->g = top->g;
	tmp->nxt = NULL;
	tmp->prv = NULL;
	return (tmp);
}

void	rr_bottom(t_stk **top)
{
	while ((*top))
	{
		if ((*top)->nxt->nxt == NULL)
			break ;
		*top = (*top)->nxt;
	}
	(*top)->nxt = NULL;
}

void	rr_stk(t_stk **top, t_stk *tmp)
{
	t_stk	*a;

	a = NULL;
	tmp = NULL;
	if (*top)
	{
		tmp = (t_stk *)malloc(sizeof(t_stk));
		if (tmp == NULL)
			return ;
		tmp = rr_swap(*top, tmp);
		a = *top;
		rr_bottom(top);
		*top = a;
		add_front(top, tmp);
	}
}

void	r_stk(t_stk **top)
{
	if (*top)
	{
		*top = (*top)->nxt;
		add_back_r(top);
	}
}
