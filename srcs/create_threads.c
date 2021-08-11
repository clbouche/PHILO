/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:38:50 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/11 14:16:31 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    *routine()
{
    printf("ca marche\n");
    return (NULL);
}

void	create_threads(t_params *params)
{
	int	i;
	pthread_t               thread_id[5];

	i = 0;
	while (i < params->data.nb_of_philo)
	{
		printf("Creating philo : [%d]\n", i);
		//pthread_create(&params->philo[i].thread_id, NULL, routine, &params->philo[i]);
		pthread_create(&thread_id[i], NULL, routine, &params->philo[i]);
		i++;
	}
}