/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:12:15 by jobject           #+#    #+#             */
/*   Updated: 2021/11/09 20:28:48 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char	**argv)
{
	t_list	*lst;
	int		i;

	check(argc, argv);
	i = 1;
	while (i < argc)
		stack(argv[i++], &lst);
	if (is_sorted(lst))
		succes_message(&lst);
	i = ft_lstsize(lst);
	if (i <= 5)
		sort_small_stack(&lst);
	else
		long_long_sort(&lst);
	return (0);
}
