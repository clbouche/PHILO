/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:38:50 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/12 15:14:27 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"




/*void	thinking(t_philo *philo)
{

}*/

/*void	sleeping(t_philo *philo)
{

}*/

void	eating(t_philo *philo)
{
	//printf("philo id : [%d]\n", philo->id);
	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(&philo->params->message);
	philo_message(philo, "has taken a fork\n");
	pthread_mutex_unlock(&philo->params->message);
	pthread_mutex_lock (philo->right_fork);
	pthread_mutex_lock(&philo->params->message);
	philo_message(philo, "has taken a fork\n");
	pthread_mutex_unlock(&philo->params->message);
	pthread_mutex_lock(&philo->params->message);
	philo_message(philo, "is eating\n");
	pthread_mutex_unlock(&philo->params->message);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
}

void	*routine(void *data)
{
	t_philo		*philo;

	philo = (t_philo *)data;
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
		pthread_create(&params->philo[i].thread, NULL,
			routine, &params->philo[i]);
		i += 2;
	}
	i = 1;
	usleep(100);
	while (i < params->data.nb_of_philo)
	{
		pthread_create(&params->philo[i].thread, NULL,
			routine, &params->philo[i]);
		i += 2;
	}
}

/*
◦timestamp_in_ms X has taken a fork
◦timestamp_in_ms X is eating
◦timestamp_in_ms X is sleeping
◦timestamp_in_ms X is thinking◦timestamp_in_ms X died
*/