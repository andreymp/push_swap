/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:07:03 by jobject           #+#    #+#             */
/*   Updated: 2021/11/09 21:19:53 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_mas_mid(int	*mas, const int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (mas[i] > mas[j])
			{
				tmp = mas[i];
				mas[i] = mas[j];
				mas[j] = tmp;	
			}
			j++;
		}
		i++;
	}
	return (mas[size / 2]);
}

static int	sort_mas_rev_mid(int	*mas, const int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (mas[i] < mas[j])
			{
				tmp = mas[i];
				mas[i] = mas[j];
				mas[j] = tmp;	
			}
			j++;
		}
		i++;
	}
	return (mas[size / 2]);
}

int	make_sorted_rev_mas(t_list	*lst)
{
	int		*mas;
	int		size;
	int		i;

	size = ft_lstsize(lst);
	i = 0;
	mas = (int *) ft_calloc(size, sizeof(int));
	while (lst && i < size)
	{
		mas[i++] = lst->content;
		lst = lst->next;
	}
	i = sort_mas_rev_mid(mas, size);
	free(mas);
	return (i);
}

int	make_sorted_mas(t_list	*lst)
{
	int		*mas;
	int		size;
	int		i;

	size = ft_lstsize(lst);
	i = 0;
	mas = (int *) ft_calloc(size, sizeof(int));
	while (lst && i < size)
	{
		mas[i++] = lst->content;
		lst = lst->next;
	}
	i = sort_mas_mid(mas, size);
	free(mas);
	return (i);
}

// Delete
void	print(t_list	*lst)
{
	while (lst)
	{
		printf("%d\n", lst->content);
		lst = lst->next;
	}
	puts("");
}