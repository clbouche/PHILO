/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:38:50 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/11 17:20:44 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_message(t_philo *philo, char *msg)
{
	//printf("timestamp_in_ms\n");
	printf("Philo %d %s\n", philo->id, msg);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork);
	pthread_mutex_lock(&philo->message);
	philo_message(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(&philo->message);
    pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(&philo->message);
	philo_message(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(&philo->message);
	//verifier que le philo a bien 2 forks avant de commencer a manger
	pthread_mutex_lock(&philo->message);
	philo_message(philo, "is eating");
	pthread_mutex_unlock(&philo->message);
}

void    *routine(void	*data)
{
	t_philo		*philo;
    
	philo = (t_philo *)data;
	if (!philo->id % 2 == 0)
		usleep(10); //mais usleep interrompt le programme dans son ensemble :( 
	eating(philo);
	//sleeping(philo);
	//thinking(philo);
	return (NULL);
}

void	create_threads(t_params *params)
{
	int	i;

	i = 0;
	while (i < params->data.nb_of_philo)
	{
		pthread_create(&params->philo[i].thread, NULL, routine, &params->philo[i]);
		i++;
	}
}

/*
◦timestamp_in_ms X has taken a fork
◦timestamp_in_ms X is eating
◦timestamp_in_ms X is sleeping
◦timestamp_in_ms X is thinking◦timestamp_in_ms X died
*/