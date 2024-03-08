/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:02:21 by rpodack           #+#    #+#             */
/*   Updated: 2023/10/17 19:58:26 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_input
{
	int	*num_phil;
	int	*t_to_live;
	int	*t_to_eat;
	int	*t_to_sleep;
	int	*nb_meals;
}	t_input;

typedef struct s_ph
{
	struct s_ph		*prev;
	struct s_ph		*start;
	int				ac;
	long long		birthtime;
	long long		last_meal;
	int				fedup;
	t_input			*in;
	char			**av;
	int				*alive;
	int				*nb;
	int				meals;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*live;
	pthread_mutex_t	*mealnum;
	pthread_mutex_t	*write;
	pthread_mutex_t	*meallock;
	int				flag_fork;
	struct s_ph		*next;
}	t_ph;

t_input		*init_input(char **av, int ac);
void		*life_of_a_thinker(void *arg);

t_ph		*ft_lstnew_p(void);
void		ft_lstadd_back_p(t_ph **lst, t_ph *new);
t_ph		*init_list(char **av, int ac);
void		create_threads(t_ph *lst);

long long	ft_time(void);
void		eat(t_ph *phil);
int			lock_forks(t_ph *phil);
void		unlock_forks(t_ph *phil);
void		finish_meal(t_ph *phil);
void		die_of_hunger(t_ph *phil);
void		ft_sleep(t_ph *phil);
int			check(t_ph *phil);
long long	ft_gettime(t_ph*phil);
int			ft_starve(t_ph *phil);
int			all_fed_up(t_ph *phil);
void		print_out(t_ph *phil, int flag);
int			cycle_of_life(t_ph *phil);
void		clean_up(t_ph *lst);
void		free_first(t_ph *lst);
int			clean_first_node(t_ph *lst);
void		clean_tmp(t_ph *tmp);
void		clean_stuff(t_ph *curr);
void		free_firstofall(t_ph *lst);
void		free_loc(t_input *in);
t_ph		*init_tmp(void);
t_input		*loc_in(char **av);
int			ft_check_arg(char *str);
int			errorcheck(int ac, char **av);
void		destroy_mutexes(t_ph *lst);
int			init_first_node(t_ph *lst);
void		keep_on_initing(t_ph *lst, int ac, char **av);

int			check_forks(t_ph *phil);
int			who_gets_served(t_ph *phil);
int			why_we_die(t_ph *phil);
int			lock_fork_for_one(t_ph *phil);
int			lock_first(t_ph *phil);
void		check_meals(t_ph *phil);

/*libft*/
int			ft_atoi(const char *nptr);

#endif