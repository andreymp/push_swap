/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_long_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:10:35 by jobject           #+#    #+#             */
/*   Updated: 2021/11/10 20:39:09 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	move(t_list	**b, int mid)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *b;
	while (tmp && tmp->content >= mid)
	{	
		i++;
		tmp = tmp->next;
	}
	if (i < ft_lstsize(*b) / 2)
		while (i--)
			ft_ra(b, 1);
	else
		while (i++ != ft_lstsize(*b))
			ft_rra(b, 1);
}

static void	chunks(t_list	**a, t_list	**b, int temp, int tmp)
{
	while (temp - 1)
	{	
		if ((*a)->content < tmp)
		{
			ft_pb(a, b);
			temp--;
		}
		else
			move(a, tmp);
	}
}

static void	push_to_b(t_list	**a, t_list	**b)
{
	int	chunk;
	int	*mas;
	int	size;
	int	tmp;
	int	temp;

	size = ft_lstsize(*a);
	mas = make_sorted_rev_mas(*a);
	chunk = size / 10;
	while (*a && chunk != size)
	{
		temp = size / 10;
		tmp = mas[chunk - 1];
		chunks(a, b, temp, tmp);
		chunk += (size / 10);
	}
	while (*a)
		ft_pb(a, b);
	free(mas);
}

static void	push_to_a(t_list	**a, t_list	**b)
{
	t_list	*tmp;
	int		i;

	while (*b)
	{
		i = 0;
		tmp = *b;
		while (tmp->content != ft_max(*b))
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

void	long_long_sort(t_list	**lst)
{
	t_list	*b;

	b = NULL;
	push_to_b(lst, &b);
	push_to_a(lst, &b);
	if (b)
		free (b);
}
