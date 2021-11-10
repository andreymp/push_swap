/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:10:33 by jobject           #+#    #+#             */
/*   Updated: 2021/11/10 20:41:18 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list	**lst, int flag)
{
	t_list	*tmp;
	int		temp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	temp = tmp->content;
	while (tmp->next)
	{
		tmp->content = tmp->next->content;
		tmp = tmp->next;
	}
	ft_lstlast(tmp)->content = temp;
	if (flag)
		ft_putendl_fd("ra", 1);
}

void	ft_rb(t_list	**lst, int flag)
{
	t_list	*tmp;
	int		temp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	temp = tmp->content;
	while (tmp->next)
	{
		tmp->content = tmp->next->content;
		tmp = tmp->next;
	}
	ft_lstlast(tmp)->content = temp;
	if (flag)
		ft_putendl_fd("rb", 1);
}

void	ft_rr(t_list	**lsta, t_list	**lstb)
{
	ft_ra(lsta, 0);
	ft_rb(lstb, 0);
	ft_putendl_fd("rr", 1);
}
