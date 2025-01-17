/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:15:24 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/18 19:24:49 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (last)
		last->next = new;
	else
		*lst = new;
}
/* 
int	main(void)
{
	char	str[] = "test";

	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;
	t_list	*ret;

	if (!(elem1 = malloc(sizeof(t_list))))
		return (0);
	if (!(elem2 = malloc(sizeof(t_list))))
		return (0);
	if (!(elem3 = malloc(sizeof(t_list))))
		return (0);

	elem1->next = elem2;
	elem2->next = elem3;
	elem3->next = NULL;

	elem3->content = (void *)str;
	ret = ft_lstlast(elem1);
	printf("\n%s\n", (char *)ret->content);
} */