/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:12:10 by jobject           #+#    #+#             */
/*   Updated: 2021/11/10 21:02:44 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list	*lst)
{
	t_list	*tmp;

	if (!lst || !lst->next)
		return (0);
	tmp = lst;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	size_3(t_list	**lsta)
{
	while (!is_sorted(*lsta))
	{
		if ((*lsta)->content < (*lsta)->next->content)
			ft_rra(lsta, 1);
		else if ((*lsta)->content == ft_max(*lsta)
			&& (*lsta)->next->content == ft_min(*lsta))
			ft_ra(lsta, 1);
		else
			ft_sa(lsta, 1);
	}
}

static void	search(t_list	**lst, int (*f)(t_list *))
{
	while ((*lst)->content != f(*lst))
	{
		if ((*lst)->next->content != f(*lst)
			&& (*lst)->next->next->content != f(*lst))
			ft_rra(lst, 1);
		else
			ft_ra(lst, 1);
	}
}

static void	size_45(t_list	**lsta)
{
	t_list	*b;
	int		size;

	b = (t_list *) malloc (sizeof(t_list));
	size = ft_lstsize(*lsta);
	if (size == 5)
	{
		search(lsta, ft_min);
		ft_pb(lsta, &b);
	}
	search(lsta, ft_max);
	ft_pb(lsta, &b);
	while (ft_lstsize(*lsta) != 3)
		ft_pb(lsta, &b);
	size_3(lsta);
	ft_pa(lsta, &b);
	ft_ra(lsta, 1);
	if (size == 5)
		ft_pa(lsta, &b);
	free(b);
}

void	sort_small_stack(t_list	**lsta)
{
	int		size;

	if (!(*lsta)->next)
		succes_message(lsta);
	size = ft_lstsize(*lsta);
	if (size == 2)
	{
		ft_sa(lsta, 1);
		succes_message(lsta);
	}
	if (size == 3)
	{
		size_3(lsta);
		succes_message(lsta);
	}
	else
	{
		size_45(lsta);
		succes_message(lsta);
	}
}
