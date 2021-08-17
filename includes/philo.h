/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:02:02 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/17 12:46:09 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
** DEFINE
*/

# define ERR_NUM "The arguments must be numerical"
# define ERR_NB_ARGS "The execution of the program requires 5 or 6 parameters"
# define ERR_NB_PHILO "No philosopher wants to eat"
# define ERR_INIT "Something went wrong with initialization"
# define ERR_MALLOC "Malloc returned NULL value"

/*
** LIBRAIRIES
*/

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

/*
** STRUCTURES
*/

typedef struct s_thread_data
{
	int				nb_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meals_per_philo;
	long long		start_time;
	pthread_mutex_t	message;
}				t_thread_data;

struct	s_params;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	left_fork;
	t_thread_data	*data;
	int				id;
}				t_philo;

typedef struct s_params
{
	t_philo			*philo;
	t_thread_data	data;
}				t_params;

/*
** FUNCTIONS
*/

void		parsing(int argc, char **argv, t_params *params);
int			create_threads(t_params *params);
int			ft_atoi(const char *str);
void		ft_error(char *error);
void		philo_message(t_philo *philo, char *msg);
long long   get_time(void);
void		ft_usleep(long int time_to_go);

#endif