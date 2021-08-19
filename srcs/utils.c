/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:56:16 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/19 14:30:12 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*is_dead(void *data)
{
	t_philo		*philo;

	philo = (t_philo *)data;
	usleep(philo->data->time_to_die);
	pthread_mutex_lock(&philo->data->mutex_eat);
	pthread_mutex_lock(&philo->data->finish);
	if (!(check_death(philo, ALIVE) && get_time() - philo->data->timer_death >=
		philo->data->time_to_die))
	{
		pthread_mutex_unlock(&philo->data->finish);
		pthread_mutex_unlock(&philo->data->mutex_eat);
		pthread_mutex_lock(&philo->data->message);
		philo_message(philo, "died\n");
		check_death(philo, DEAD);
	}
	pthread_mutex_unlock(&philo->data->mutex_eat);
	pthread_mutex_unlock(&philo->data->finish);
	pthread_mutex_unlock(&philo->data->message);
	return (NULL);
}

int		check_death(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->data->end);
	if (i)
		philo->data->dead_signal = i;
	if (philo->data->dead_signal)
	{
		pthread_mutex_unlock(&philo->data->end);
		return (DEAD);
	}
	pthread_mutex_unlock(&philo->data->end);
	return (ALIVE);
}

void	ft_error(char *error)
{
	printf("Error : %s\n", error);
	exit(-1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	rslt;

	i = 0;
	sign = 1;
	rslt = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			rslt = rslt * 10 + (str[i] - '0');
			i++;
		}
		else
			ft_error(ERR_NUM);
	}
	return (rslt * sign);
}
