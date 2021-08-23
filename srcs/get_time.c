/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:16:47 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/23 10:12:37 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long   get_time(void)
{
    struct timeval  tp;
    long long            milliseconds;

	milliseconds = 0;
    gettimeofday(&tp, NULL);
    milliseconds = tp.tv_sec * 1000;
    milliseconds += tp.tv_usec / 1000;
    return (milliseconds);
}

void	philo_message(t_philo *philo, char *msg)
{
	long long	time;

	time = -1;
	time = get_time() - philo->data->start_time;
	if (!check_death(philo, ALIVE))
		printf("%lli   Philo %d %s\n", time, philo->id, msg);
}

void	ft_msleep(long long time_to_go)
{
	long long	time;

	time = 0;
	time = get_time();
	while ((get_time() - time) < time_to_go)
		usleep(time_to_go / 10);
}
