/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:27:18 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/19 13:09:13 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_stk(t_stk **top)
{
	int		i;
	int		k;
	int		m;
	t_stk	*tmp;

	tmp = NULL;
	if ((*top) && (*top)->nxt)
	{
		tmp = *top;
		i = (*top)->num;
		k = (*top)->i;
		m = (*top)->g;
		(*top)->num = (*top)->nxt->num;
		(*top)->i = (*top)->nxt->i;
		(*top)->g = (*top)->nxt->g;
		(*top)->nxt->num = i;
		(*top)->nxt->i = k;
		(*top)->nxt->g = m;
		(*top) = tmp;
	}
}
