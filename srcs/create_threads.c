/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:38:50 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/11 15:11:49 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    *routine(void	*data)
{
	t_philo		*philo;
    
	philo = (t_philo *)data;
	printf("Creating philo : [%d]\n", philo->id);
    return (NULL);
}

void	create_threads(t_params *params)
{
	int	i;

	i = 0;
	while (i < params->data.nb_of_philo)
	{
		pthread_create(&params->philo[i].thread_id, NULL, routine, &params->philo[i]);
		i++;
	}
}