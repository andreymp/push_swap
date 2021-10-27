/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:12:02 by jobject           #+#    #+#             */
/*   Updated: 2021/10/27 20:12:04 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_list	**lsta, t_list	**lstb)
{
	t_list	*temp;

	if (!*lstb)
		return ;
	temp = *lstb;
	*lstb = (*lstb)->next;
	ft_lstadd_front(lsta, temp);
	ft_putendl_fd("pa", 1);
}

void	ft_pb(t_list	**lsta, t_list	**lstb)
{
	t_list	*temp;

	if (!*lsta)
		return ;
	temp = *lsta;
	*lsta = (*lsta)->next;
	ft_lstadd_front(lstb, temp);
	ft_putendl_fd("pb", 1);
}
