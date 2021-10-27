/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:09:35 by jobject           #+#    #+#             */
/*   Updated: 2021/10/27 20:09:36 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atoi_long(const char	*nptr)
{
	char				*str;
	long long int		i;
	long long int		sign;
	long long int		res;

	str = (char *) nptr;
	i = 0;
	res = 0;
	sign = 1;
	while (str + i && (*(str + i) == '\n' || *(str + i) == '\t'
			|| *(str + i) == '\v' || *(str + i) == '\f' || *(str + i) == '\r'
			|| *(str + i) == ' '))
		i++;
	if (*(str + i) == '-')
		sign *= -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		res = res * 10 + (*(str + i) - 48);
		i++;
	}
	return (res * sign);
}

int	ft_max(t_list	*lst)
{
	t_list	*a;
	int		max;

	a = lst;
	max = INT_MIN;
	while (a)
	{
		if (a->content > max)
			max = a->content;
		a = a->next;
	}
	return (max);
}

int	ft_min(t_list	*lst)
{
	t_list	*a;
	int		min;

	a = lst;
	min = INT_MAX;
	while (a)
	{
		if (a->content < min)
			min = a->content;
		a = a->next;
	}
	return (min);
}

void	succes_message(t_list	**lst)
{
	ft_lstclear(lst, del);
	exit(EXIT_SUCCESS);
}

void	del(int content)
{
	content = 0;
}
