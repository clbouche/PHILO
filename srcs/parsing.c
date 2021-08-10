/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:16:47 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/10 17:11:43 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	recup_args(int argc, char **argv, t_thread_data *data)
{
	t_philo			*philo;

	if (argc == 5 || argc == 6)
	{
		data->nb_of_philo = ft_atoi(argv[1]);
		data->time_to_die = ft_atoi(argv[2]);
		data->time_to_eat = ft_atoi(argv[3]);
		data->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			data->nb_meals_per_philo = ft_atoi(argv[5]);
		else
			data->nb_meals_per_philo = -1;
	}
	else
		ft_error(ERR_NB_ARGS);
	printf("check nb of philo : %d\n", data->nb_of_philo);
	printf("check time to die : %d\n", data->time_to_die);
	printf("check time to eat : %d\n", data->time_to_eat);
	printf("check time to sleep : %d\n", data->time_to_sleep);
	printf("check nb meals per philo : %d\n", data->nb_meals_per_philo);
}