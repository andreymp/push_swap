# include "push_swap.h"

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
	// int		i;
	// t_list	*tmp;
	int		mid;
	int		half;

	// tmp = *b;
	while (ft_lstsize(*b) > 2)
	{
		half = ft_lstsize(*b) / 2;
		mid = make_sorted_rev_mas(*b);
		while (half)
		{
			if ((*b)->content > mid)
			{
				ft_pa(a, b);
				half--;
			}
			else
				ft_rb(b, 1);
		}
		// i = 0;
		// tmp = *b;
		// while (tmp->content != ft_max(tmp))
		// {	
		// 	i++;
		// 	tmp = tmp->next;
		// }
		// if (i < ft_lstsize(*b) / 2)
		// 	while (i--)
		// 		ft_rb(b, 1);
		// else
		// 	while (i++ != ft_lstsize(*b))
		// 		ft_rrb(b, 1);
		// ft_pa(a, b);
	}
	if (is_sorted(*b))
		ft_sb(b, 1);
	ft_pa(a, b);
	ft_pa(a, b);
}

void	long_long_sort(t_list	**lst)
{
	t_list	*b;

	b = NULL;
	push_to_b(lst, &b);
	push_to_a(lst, &b);
	// while (!is_sorted(*lst))
	// {
	// 	if ((*lst)->content > (*lst)->next->content)
	// 		ft_sa(lst, 1);
	// 	ft_ra(lst, 1);
	// }                  TO_THINK_ABOUT
	print(*lst);
	if (b)
		free (b);
}