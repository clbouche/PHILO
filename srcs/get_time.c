/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:16:47 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/19 14:30:15 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long   get_time(void)
{
    struct timeval  tp;
    long long            milliseconds;

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
		printf("%lld   Philo %d %s\n", time, philo->id, msg);
}


/*void	ft_usleep(long int time_to_go)
{
	long int	time;

	time = 0;
	time = actual_time();
	//printf("check time start : [%ld]\n", time);
	while ((actual_time() - time) < time_to_go)
	{
		//printf("check time start while : [%ld]\n", time);
		//printf("check time to go : [%ld]\n", time_to_go);
		usleep(time_to_go / 10);
		//time = actual_time();
		//printf("check actual time : %ld\n", time);
	}
}*/