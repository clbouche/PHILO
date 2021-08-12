/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:01:18 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/12 15:14:33 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	initialisation(t_params *params)
{
	int	i;

	i = 0;
	params->philo = malloc(sizeof(t_philo) * params->data.nb_of_philo);
	while (i < params->data.nb_of_philo)
	{
		params->philo[i].id = i + 1;
		pthread_mutex_init(&params->philo[i].left_fork, NULL);
		pthread_mutex_init(&params->message, NULL);
		params->philo[i].right_fork = &params->philo[(i + 1) % params->data.nb_of_philo].left_fork;
		params->philo[i].params = params;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_params	params;
	int			i;

	i = 0;
	parsing(argc, argv, &params);
	initialisation(&params);
	create_threads(&params);
	free(params.philo);
	return (0);
}
