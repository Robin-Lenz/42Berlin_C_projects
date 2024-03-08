/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:38:20 by rpodack           #+#    #+#             */
/*   Updated: 2023/06/24 20:04:19 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_psl
{
	int				content;
	int				curr_pos;
	int				index;
	struct s_psl	*next;
}	t_psl;

t_psl			*init_stack(char **av, t_psl **a);

t_psl			*ft_lstnew_p(int content);
void			ft_lstadd_back_p(t_psl **lst, t_psl *new);
t_psl			*ft_lstlast_p(t_psl *lst);
int				ft_lstsize_p(t_psl *lst);
void			printlist(t_psl *a);

void			ft_sa(t_psl **a);
void			ft_swap(t_psl **a);
void			ft_push(t_psl **a, t_psl **b);
void			ft_revrotate(t_psl **a);
void			ft_rotate(t_psl **a);
void			ft_sb(t_psl **b);
void			ft_ss(t_psl **a, t_psl **b);
void			ft_pa(t_psl **a, t_psl **b);
void			ft_pb(t_psl **a, t_psl **b);
void			ft_ra(t_psl **a);
void			ft_rb(t_psl **b);
void			ft_rr(t_psl **a, t_psl **b);
void			ft_rra(t_psl **a);
void			ft_rrb(t_psl **b);
void			ft_rrr(t_psl **a, t_psl **b);

int				is_duplicate(t_psl *tmp, t_psl *a);
int				is_all_digit(char **av);
int				is_sorted(t_psl *a);

void			free_a(t_psl **a);
void			error(void);
void			error_after_init(t_psl **a, t_psl **tmp);
void			free_exit(t_psl **a);
void			free_split(char **split, int i);
void			free_double(char **split);
void			free_sorted_split(char **split, t_psl **a);

void			set_index(t_psl **a);
void			set_curr_pos(t_psl **a);
int				find_min(t_psl **a);
void			find_max(t_psl **a, int *len, int min_value);

void			sort(t_psl **a, t_psl **b);
void			sort_three(t_psl **a);
t_psl			*lowest_index(t_psl *a);
t_psl			*find_max_index(t_psl **a);

void			chunk_em_up(t_psl **a, t_psl **b, int len_lst);
void			bring_em_home(t_psl **a, t_psl **b, int len_lst);
void			get_lines(t_psl **a, t_psl **b, int *flag, t_psl *last_a);
void			if_elses(t_psl **a, t_psl **b, t_psl *max_b, int *flag);
t_psl			*get_last(t_psl **a, t_psl *last_a);
int				handle_quotes(char **av, t_psl *a, t_psl *tmp_max);

long long int	ft_atoi(const char *nptr, t_psl **a, t_psl **tmp);
t_psl			*init_stack_split(char **av, t_psl **a);
void			allocate_em(t_psl **a, t_psl *tmp, char **av, int i);

#endif