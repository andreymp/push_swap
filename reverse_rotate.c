/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:11:22 by jobject           #+#    #+#             */
/*   Updated: 2021/11/09 13:43:54 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list	**lst, int flag)
{
	// t_list	*tmp;
	// int		size;
	// int		i;

	// if (!*lst || !(*lst)->next)
	// 	return ;
	// tmp = *lst;
	// i = 0;
	// size = ft_lstsize(tmp) - 1;
	// while (i < size)
	// {
	// 	ft_ra(lst, 0);
	// 	i++;
	// }
	t_list		*first_list;
	t_list		*rotate_list;
	t_list		*penultimate_list;

	if ((*lst) == NULL || (*lst)->next == NULL)
		return ;
	first_list = *lst;
	penultimate_list = *lst;
	while (penultimate_list->next->next != NULL)
		penultimate_list = penultimate_list->next;
	rotate_list = penultimate_list->next;
	penultimate_list->next = NULL;
	rotate_list->next = first_list;
	*lst = rotate_list;
	if (flag)
		ft_putendl_fd("rra", 1);
}

void	ft_rrb(t_list	**lst, int flag)
{
	t_list	*tmp;
	int		size;
	int		i;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	i = 0;
	size = ft_lstsize(tmp) - 1;
	while (i < size)
	{
		ft_rb(lst, 0);
		i++;
	}
	if (flag)
		ft_putendl_fd("rrb", 1);
}

void	ft_rrr(t_list	**lsta, t_list	**lstb)
{
	ft_rra(lsta, 0);
	ft_rrb(lstb, 0);
	ft_putendl_fd("rrr", 1);
}
