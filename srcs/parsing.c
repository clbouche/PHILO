/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:16:47 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/13 15:12:48 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	parsing(int argc, char **argv, t_params *params)
{
	params->data.start_time = actual_time();
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
	}
	else
		ft_error(ERR_NB_ARGS);
}
