/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:01:18 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/13 13:15:24 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ending(t_params *params)
{
	int i;

	i = 0;
	//faire pthread_join ici je crois
	while (++i < params->data.nb_of_philo)
		pthread_mutex_destroy(&params->philo[i].left_fork);
	pthread_mutex_destroy(&params->message);
	free(params->philo);
}

int	initialisation(t_params *params)
{
	int	i;

	i = 0;
	params->philo = malloc(sizeof(t_philo) * params->data.nb_of_philo);
	if (!params->philo)
		ft_error(ERR_MALLOC);
	while (i < params->data.nb_of_philo)
	{
		params->philo[i].id = i + 1;
		pthread_mutex_init(&params->philo[i].left_fork, NULL);
		pthread_mutex_init(&params->message, NULL);
		params->philo[i].right_fork = &params->philo[(i + 1)
			% params->data.nb_of_philo].left_fork;
		params->philo[i].params = params;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_params	params;
	int			i;

	i = 0;
	parsing(argc, argv, &params);
	if (!initialisation(&params))
	{
		free(params.philo);
		ft_error(ERR_INIT);
	}
	create_threads(&params);
	ending(&params);
	return (0);
}
