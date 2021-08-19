/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:38:50 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/19 14:30:02 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->message);
	philo_message(philo, "is thinking\n");
	pthread_mutex_unlock(&philo->data->message);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->message);
	philo_message(philo, "is sleeping\n");
	pthread_mutex_unlock(&philo->data->message);
	usleep(philo->data->time_to_sleep);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(&philo->data->message);
	philo_message(philo, "has taken a fork\n");
	pthread_mutex_unlock(&philo->data->message);
	pthread_mutex_lock (philo->right_fork);
	pthread_mutex_lock(&philo->data->message);
	philo_message(philo, "has taken a fork\n");
	pthread_mutex_unlock(&philo->data->message);
	pthread_mutex_lock(&philo->data->mutex_eat);
	philo->data->timer_death = get_time();
	pthread_mutex_lock(&philo->data->mutex_eat);
	pthread_mutex_lock(&philo->data->message);
	philo_message(philo, "is eating\n");
	pthread_mutex_unlock(&philo->data->message);
	usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
}

void	*routine(void *data)
{
	t_philo		*philo;

	philo = (t_philo *)data;
	while (!check_death(philo, ALIVE))
	{
		pthread_create(&philo->thread_death, NULL, is_dead, data);
		eating(philo);
		sleeping(philo);
		thinking(philo);
		if ()
		//if each philo have full belly : fin du jeu aussi
	}
	return (NULL);
}

int	create_threads(t_params *params)
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
		if (pthread_create(&params->philo[i].thread, NULL,
			routine, &params->philo[i]) != 0)
			ft_error(ERR_THREAD);
		i += 2;
	}
	return (1);
}
