/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:49:46 by jobject           #+#    #+#             */
/*   Updated: 2021/11/10 20:28:38 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b(t_list	**a, t_list	**b)
{
	int		mid;
	int		half;

	while (ft_lstsize(*a) > 2)
	{
		half = ft_lstsize(*a) / 2;
		mid = make_sorted_mas(*a);
		while (half)
		{
			if ((*a)->content < mid)
			{
				ft_pb(a, b);
				half--;
			}
			else
				ft_ra(a, 1);
		}
	}
	if (!is_sorted(*a))
		ft_sa(a, 1);
}

static void	push_to_a(t_list	**a, t_list	**b)
{
	int		i;
	t_list	*tmp;

	tmp = *b;
	while (*b)
	{
		i = 0;
		tmp = *b;
		while (tmp->content != ft_max(tmp))
		{	
			i++;
			tmp = tmp->next;
		}
		if (i < ft_lstsize(*b) / 2)
			while (i--)
				ft_rb(b, 1);
		else
			while (i++ != ft_lstsize(*b))
				ft_rrb(b, 1);
		ft_pa(a, b);
	}
}

void	long_sort(t_list	**lst)
{
	t_list	*b;

	b = NULL;
	push_to_b(lst, &b);
	push_to_a(lst, &b);
	if (b)
		free (b);
}
