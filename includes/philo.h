/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:02:02 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/10 15:35:31 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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


/*detail pour chaque philo*/
typedef struct s_philo
{
	//pthread_mutex_t	right_fork;
	//pthread_mutex_t	left_fork;
	int		thread_id;
	char	*message;
	//t_thread_data	*data;

}				t_philo;

/*data que les threads partage*/
typedef	struct s_thread_data
{
	pthread_t		nb_of_philo; //arg1
	int				time_to_die; //arg2
	int				time_to_eat;//arg3
	int				time_to_sleep; //arg4
	int				nb_meals_per_philo; //(arg 5)
}				t_thread_data;


/*
** FUNCTIONS
*/

void	recup_args(int argc, char **argv);

#endif