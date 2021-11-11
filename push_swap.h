/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:12:06 by jobject           #+#    #+#             */
/*   Updated: 2021/11/11 15:59:27 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

long long int	ft_atoi_long(const char	*nptr);
void			error_message(void);
void			succes_message(t_list	**lst);
void			stack(char	*str, t_list	**lst);
void			check(int argc, char	**argv);
int				is_sorted(t_list	*lst);
int				ft_max(t_list	*lst);
int				ft_min(t_list	*lst);
void			del(int content);
void			ft_sa(t_list	**lst, int flag);
void			ft_sb(t_list	**lst, int flag);
void			ft_ss(t_list	**lsta, t_list	**lstb);
void			ft_pa(t_list	**lsta, t_list	**lstb);
void			ft_pb(t_list	**lsta, t_list	**lstb);
void			ft_ra(t_list	**lst, int flag);
void			ft_rb(t_list	**lst, int flag);
void			ft_rr(t_list	**lsta, t_list	**lstb);
void			ft_rra(t_list	**lst, int flag);
void			ft_rrb(t_list	**lst, int flag);
void			ft_rrr(t_list	**lsta, t_list	**lstb);
void			sort_small_stack(t_list	**lsta);
void			long_sort(t_list	**lst);
void			size_3(t_list	**lsta);
int				make_sorted_mas(t_list	*lst);
void			long_long_sort(t_list	**lst);
int				*make_sorted_rev_mas(t_list	*lst);

#endif