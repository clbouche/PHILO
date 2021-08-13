/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 14:24:31 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/13 16:01:48 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long int	actual_time()
{
	long int		time;
	struct timeval	data;

	gettimeofday(&data, NULL);
	time = (data.tv_sec * 1000) + (data.tv_usec / 1000);
	return (time);
}

/*void	ft_usleep(long int time_to_go)
{
	long int	time;

	time = actual_time();
	printf("check time start : [%ld]\n", time);
	while ((actual_time() - time) < time_to_go)
	{
		printf("check time start while : [%ld]\n", time);
		printf("check time to go : [%ld]\n", time_to_go);
		usleep(time_to_go / 10);
		time = actual_time();
		printf("check actual time : %ld\n", time);
	}
}*/