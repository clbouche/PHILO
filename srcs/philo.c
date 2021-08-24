/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:01:18 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/24 14:25:46 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ending(t_params *params)
{
	int	i;

	i = -1;
	while (++i < params->data.nb_of_philo)
		pthread_join(params->philo[i].thread, NULL);
	i = -1;
	while (++i < params->data.nb_of_philo)
		pthread_join(params->philo[i].thread_death, NULL);
	while (++i < params->data.nb_of_philo)
		pthread_mutex_destroy(&params->philo[i].left_fork);
	pthread_mutex_destroy(&params->data.message);
	free(params->philo);
}

void	init_mutex(t_params *params)
{
	pthread_mutex_init(&params->data.message, NULL);
	pthread_mutex_init(&params->data.end, NULL);
	pthread_mutex_init(&params->data.finish, NULL);
	pthread_mutex_init(&params->data.mutex_eat, NULL);
}

int	initialisation(t_params *params)
{
	int	i;

	i = -1;
	params->data.start_time = get_time();
	params->data.dead_signal = 0;
	params->data.full_belly = 0;
	params->philo = malloc(sizeof(t_philo) * params->data.nb_of_philo);
	if (!params->philo)
		ft_error(ERR_MALLOC);
	init_mutex(params);
	while (++i < params->data.nb_of_philo)
	{
		params->philo[i].timer_death = params->data.start_time;
		params->philo[i].id = i + 1;
		params->philo[i].nb_meal = 0;
		params->philo[i].right_fork = NULL;
		if (params->data.nb_of_philo == 1)
			return (1);
		pthread_mutex_init(&params->philo[i].left_fork, NULL);
		if (i == params->data.nb_of_philo - 1)
			params->philo[i].right_fork = &params->philo[0].left_fork;
		else
			params->philo[i].right_fork = &params->philo[i + 1].left_fork;
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
		params->data.time_to_die = ft_atoi(argv[2]);
		params->data.time_to_eat = ft_atoi(argv[3]);
		params->data.time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			params->data.nb_meals_per_philo = ft_atoi(argv[5]);
		else
			params->data.nb_meals_per_philo = -1;
		if (params->data.time_to_die < 60
			|| params->data.time_to_eat < 60
			|| params->data.time_to_sleep < 60)
			ft_error(ERR_ARG);
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
