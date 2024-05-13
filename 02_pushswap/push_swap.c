/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:49:02 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/26 15:10:18 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

char	*trim_log(char *str)
{
	str = ft_replace(str, "\npa\npb\n", "\n");
	str = ft_replace(str, "\npb\npa\n", "\n");
	str = ft_replace(str, "\nsa\nsb\n", "\nss\n");
	str = ft_replace(str, "\nsb\nsa\n", "\nss\n");
	str = ft_replace(str, "\nra\nrb\n", "\nrr\n");
	str = ft_replace(str, "\nrb\nra\n", "\nrr\n");
	str = ft_replace(str, "\nrra\nrrb\n", "\nrrr\n");
	str = ft_replace(str, "\nrrb\nrra\n", "\nrrr\n");
	str = ft_replace(str, "\nsa\nss\nsb\n", "\nss\nss\n");
	str = ft_replace(str, "\nsb\nss\nsa\n", "\nss\nss\n");
	str = ft_replace(str, "\nra\nrr\nrb\n", "\nrr\nrr\n");
	str = ft_replace(str, "\nrb\nrr\nrb\n", "\nrr\nrr\n");
	str = ft_replace(str, "\nrra\nrrr\nrrb\n", "\nrrr\nrrr\n");
	str = ft_replace(str, "\nrrb\nrrr\nrra\n", "\nrrr\nrrr\n");
	return (str);
}

void	push_swap(t_var *ps, int ac, char **av)
{
	t_stk	*stk;

	stk = NULL;
	ps->split = fill_args(ps, ac, av);
	check_dup(ps->split, ps);
	check_numbers(ps->split, ps);
	fill_list(ps, ps->split, stk);
	free_stk(&stk);
	if (check_sort(&ps->a_stk) == 1)
		ft_exit_ps("Error\n", 0, ps);
	ps->len = list_size(ps->a_stk);
	ft_set_idx(ps->a_stk);
	ps->pow = find_power(ps->len);
	if (ps->len <= 3)
		sort_small(&(ps->a_stk), &(ps->b_stk), ps->len, ps);
	else if (ps->len > 3)
		sort_big(&(ps->a_stk), &(ps->b_stk), ps);
	ft_putstr_fd(ps->log, ps->fd);
	free(ps->log);
	free_stk(&(ps->a_stk));
	free_stk(&(ps->b_stk));
}

int	main(int ac, char **av)
{
	t_var	*ps;

	ps = NULL;
	if (ac < 2)
		ft_exit_ps("Error\n", 0, ps);
	else
	{
		ps = ft_init_var(ps);
		push_swap(ps, ac, av);
		free(ps);
		ps = NULL;
	}
}
