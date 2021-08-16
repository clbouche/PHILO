/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:16:47 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/16 17:09:29 by clbouche         ###   ########.fr       */
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
	//long long	time;
	//printf("start time : %lld\n", philo->params->data.start_time);
	//time = get_time() - philo->params->data.start_time;
	//printf("%lld", time);
	printf("   Philo %d %s\n", philo->id, msg);
}

/*int main(void)
{
    long long start_time;
		
		// Remember when we started
    start_time = get_time();

    while (1)
    {
				// Print time from start, in ms
        printf("%lld\n", get_time() - start_time);

				// Sleep 200 times 1000 microseconds (1 millisecond)
        usleep(200 * 1000);
    }
}*/


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