/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:09:41 by jobject           #+#    #+#             */
/*   Updated: 2021/10/27 20:09:43 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list	**lst, int flag)
{
	int	tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = tmp;
	if (flag)
		ft_putendl_fd("sa", 1);
}

void	ft_sb(t_list	**lst, int flag)
{
	int	tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = tmp;
	if (flag)
		ft_putendl_fd("sb", 1);
}

void	ft_ss(t_list	**lsta, t_list	**lstb)
{
	ft_sa(lsta, 0);
	ft_sb(lstb, 0);
	ft_putendl_fd("ss", 1);
}
