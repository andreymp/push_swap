#include "push_swap.h"

void	error_message(void)
{
	ft_putendl_fd("Error", 1);
	exit(EXIT_FAILURE);
}

void check_input(char	*str)
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

void	check_dup(int argc, char	**argv)
{
	int i;
	int j;

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

int main(int argc, char	**argv)
{
	int i = 1;
	t_list	*lst;

	if (argc < 2)
		error_message();
	while (i < argc)
		check_input(argv[i++]);
	check_dup(argc, argv);
	i = 1;
	while (i < argc)
		stack(argv[i++], &lst);
	while (lst)
	{
		printf("%d\n", lst->content);
		lst = lst->next;
	}
}