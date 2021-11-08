/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:12:10 by jobject           #+#    #+#             */
/*   Updated: 2021/11/08 20:52:25 by jobject          ###   ########.fr       */
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
	t_list	*a;

	a = *lsta;
	while (!is_sorted(a))
	{
		if (a->content < a->next->content)
			ft_rra(&a, 1);
		else if (a->content == ft_max(a) && a->next->content == ft_min(a))
			ft_ra(&a, 1);
		else
			ft_sa(&a, 1);
	}
}

static void	search(t_list	**lst, int (*f)(t_list *))
{
	t_list	*a;

	a = *lst;
	while (a->content != f(a))
	{
		if (a->next->content != f(a) && a->next->next->content != f(a))
			ft_rra(&a, 1);
		else
			ft_ra(&a, 1);
	}
}

static void	size_45(t_list	**lsta)
{
	t_list	*a;
	t_list	*b;
	int		size;

	a = *lsta;
	b = (t_list *) malloc (sizeof(t_list));
	size = ft_lstsize(a);
	if (size == 5)
	{
		search(&a, ft_min);
		ft_pb(&a, &b);
	}
	search(&a, ft_max);
	ft_pb(&a, &b);
	while (ft_lstsize(a) != 3)
		ft_pb(&a, &b);
	size_3(&a);
	while (ft_lstsize(a) != size)
		ft_pa(&a, &b);
	free(b);
}

void	sort_small_stack(t_list	**lsta)
{
	t_list	*a;
	int		size;

	if (!(*lsta)->next)
		succes_message(lsta);
	a = *lsta;
	size = ft_lstsize(a);
	if (size == 2)
	{
		ft_sa(lsta, 1);
		succes_message(lsta);
	}
	if (size == 3)
	{
		size_3(&a);
		succes_message(lsta);
	}
	else
	{
		size_45(&a);
		succes_message(lsta);
	}
}
