/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:12:18 by jobject           #+#    #+#             */
/*   Updated: 2021/10/27 20:13:55 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message(void)
{
	ft_putendl_fd("Error", 1);
	exit(EXIT_FAILURE);
}

static void	check_input(char	*str)
{
	long long int	i;
	long long int	temp;

	i = 0;
	while (*(str + i))
	{
		if (!ft_isdigit(*(str + i)) && *(str + i) != '-')
			error_message();
		i++;
	}
	temp = ft_atoi_long(str);
	if (temp < INT_MIN || temp > INT_MAX)
		error_message();
}

static void	check_dup(int argc, char	**argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				error_message();
			j++;
		}
		i++;
	}
}

void	check(int argc, char	**argv)
{
	int	i;

	if (argc < 2)
		error_message();
	i = 1;
	while (i < argc)
		check_input(argv[i++]);
	check_dup(argc, argv);
}

void	stack(char	*str, t_list	**lst)
{
	t_list	*p;

	if (!lst)
		*lst = ft_lstnew(ft_atoi(str));
	else
	{
		p = ft_lstnew(ft_atoi(str));
		ft_lstadd_front(lst, p);
	}
}
