/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:02:02 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/11 16:54:23 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
** DEFINE
*/

#define ERR_NUM "The arguments must be numerical"
#define ERR_NB_ARGS "The execution of the program requires 5 or 6 parameters"
#define ERR_NB_PHILO "No philosopher wants to eat"

/*
** LIBRAIRIES
*/

#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
** STRUCTURES
*/

typedef	struct s_thread_data
{
	int	nb_of_philo; //arg1
	int	time_to_die; //arg2
	int	time_to_eat;//arg3
	int	time_to_sleep; //arg4
	int	nb_meals_per_philo; //(arg 5)
}				t_thread_data;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	message;
	//t_thread_data	data;
	int				id;
}				t_philo;

typedef	struct	s_params
{
	t_philo			*philo;
	t_thread_data	data;
}				t_params;


/*
** FUNCTIONS
*/

void	parsing(int argc, char **argv, t_params *params);
void	create_threads(t_params *params);
int		ft_atoi(const char *str);
void	ft_error(char *error);

#endif