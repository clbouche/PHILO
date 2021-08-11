/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:16:47 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/11 16:36:22 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
	}
	else
		ft_error(ERR_NB_ARGS);
	printf("check nb of philo : %d\n", params->data.nb_of_philo);
	printf("check time to die : %d\n", params->data.time_to_die);
	printf("check time to eat : %d\n", params->data.time_to_eat);
	printf("check time to sleep : %d\n", params->data.time_to_sleep);
	printf("check nb meals per philo : %d\n\n\n", params->data.nb_meals_per_philo);
}