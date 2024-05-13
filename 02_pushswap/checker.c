/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:21:11 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/20 20:49:17 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(t_var *ps, int ac, char **av)
{
	t_stk	*stk;

	stk = NULL;
	ps->split = fill_args(ps, ac, av);
	check_dup(ps->split, ps);
	check_numbers(ps->split, ps);
	fill_list(ps, ps->split, stk);
	free_stk(&stk);
	ps->len = list_size(ps->a_stk);
	ft_set_idx(ps->a_stk);
}

char	*ft_checker(t_stk **a, t_stk **b, t_var *ps, char *line)
{
	if (!ft_strcmp(line, "pa\n"))
		pick_case(a, b, PA, ps);
	else if (!ft_strcmp(line, "pb\n"))
		pick_case(a, b, PB, ps);
	else if (!ft_strcmp(line, "ra\n"))
		pick_case(a, b, RA, ps);
	else if (!ft_strcmp(line, "rra\n"))
		pick_case(a, b, RRA, ps);
	else if (!ft_strcmp(line, "rb\n"))
		pick_case(a, b, RB, ps);
	else if (!ft_strcmp(line, "rrb\n"))
		pick_case(a, b, RRB, ps);
	else if (!ft_strcmp(line, "sa\n"))
		pick_case(a, b, SA, ps);
	else if (!ft_strcmp(line, "sb\n"))
		pick_case(a, b, SB, ps);
	else if (!ft_strcmp(line, "ss\n"))
		pick_case(a, b, SS, ps);
	else if (!ft_strcmp(line, "rr\n"))
		pick_case(a, b, RR, ps);
	else if (!ft_strcmp(line, "rrr\n"))
		pick_case(a, b, RRR, ps);
	else
		ft_exit_ps("Error\n", 1, ps);
	return (get_next_line(0));
}

void	line_checker(t_stk **a, t_stk **b, t_var *ps, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = ft_checker(a, b, ps, line);
		free(tmp);
	}
	if (!check_sort(a))
	{
		write(1, "KO\n", 3);
	}
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int ac, char **av)
{
	t_var	*ps;
	char	*line;

	ps = NULL;
	if (ac < 2)
		ft_exit_ps("", 1, ps);
	else
	{
		ps = ft_init_var(ps);
		checker(ps, ac, av);
		line = get_next_line(0);
		if (!line && !check_sort(&(ps->a_stk)))
			write(1, "KO\n", 3);
		else if (!line && check_sort(&(ps->a_stk)))
			write(1, "OK\n", 3);
		else
			line_checker(&(ps->a_stk), &(ps->b_stk), ps, line);
		free_stk(&(ps->a_stk));
		free_stk(&(ps->b_stk));
		free(ps->log);
		free(ps);
		ps = NULL;
	}
	return (0);
}
