#include "push_swap.h"

static void	push_min_to_b(t_list	**a, t_list	**b)
{
	t_list	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (tmp->content != ft_min(tmp))
	{
		tmp = tmp->next;
		i++;
	}
	if (i <= ft_lstsize(*a) / 2)
		while (i--)
			ft_ra(a, 1);
	else
		while (i++ != ft_lstsize(*a))
			ft_rra(a, 1);
	ft_pb(a, b);
}

static void	man_with_b(t_list	**a, t_list	*b)
{
	int		size;

	size = ft_lstsize(*a);
	while (ft_lstsize(*a) != 3)
		push_min_to_b(a,  &b);
	size_3(a);
	while (ft_lstsize(*a) != size)
		ft_pa(a, &b);
}

void	long_sort(t_list	**lst)
{
	t_list	*b;
	t_list	*a;

	b = NULL;
	a = *lst;
	man_with_b(&a, b);
	a = *lst;
	if (b)
		free (b);
}