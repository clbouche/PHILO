/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:01:18 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/17 12:48:07 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ending(t_params *params)
{
	int i;

	i = 0;
	while (++i < params->data.nb_of_philo)
		pthread_join(params->philo[i].thread, NULL);
	while (++i < params->data.nb_of_philo)
		pthread_mutex_destroy(&params->philo[i].left_fork);
	pthread_mutex_destroy(&params->data.message);
	free(params->philo);
}

int	initialisation(t_params *params)
{
	int	i;

	i = 0;
	params->data.start_time = get_time();
	params->philo = malloc(sizeof(t_philo) * params->data.nb_of_philo);
	if (!params->philo)
		ft_error(ERR_MALLOC);
	pthread_mutex_init(&params->data.message, NULL);
	while (i < params->data.nb_of_philo)
	{
		params->philo[i].data = &params->data;
		params->philo[i].id = i + 1;
		params->philo[i].right_fork= NULL;
		pthread_mutex_init(&params->philo[i].left_fork, NULL);
		if (i == params->data.nb_of_philo == 1)
			params->philo[i].right_fork = &params->philo[0].left_fork;
		else
			params->philo[i].right_fork = &params->philo[i + 1].left_fork;
		i++;
	}
	return (1);
}

void	parsing(int argc, char **argv, t_params *params)
{
	if (argc == 5 || argc == 6)
	{
		params->data.nb_of_philo = ft_atoi(argv[1]);
		if (params->data.nb_of_philo < 1)
			ft_error(ERR_NB_PHILO);
		params->data.time_to_die = ft_atoi(argv[2]) * 1000; 
		params->data.time_to_eat = ft_atoi(argv[3]) * 1000;
		params->data.time_to_sleep = ft_atoi(argv[4]) * 1000;
		if (argc == 6)
			params->data.nb_meals_per_philo = ft_atoi(argv[5]);
		else
			params->data.nb_meals_per_philo = -1;
		//checker si un arg est negatif
	}
	else
		ft_error(ERR_NB_ARGS);
}

int	main(int argc, char **argv)
{
	t_params	params;
	int			i;

	i = 0;
	parsing(argc, argv, &params);
	if (!initialisation(&params) || !create_threads(&params))
	{
		free(params.philo);
		ft_error(ERR_INIT);
	}
	ending(&params);
	return (0);
}
