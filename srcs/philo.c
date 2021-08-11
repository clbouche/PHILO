/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:01:18 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/11 17:18:06 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	initialisation(t_params *params)
{
	int i;

	i = 0;
	params->philo = malloc(sizeof(t_philo) * params->data.nb_of_philo);
	while(i < params->data.nb_of_philo)
	{
		params->philo[i].id = i + 1; //chaque philo recoit un nb allant de 1 a N
		pthread_mutex_init(&params->philo[i].right_fork, NULL);
		pthread_mutex_init(&params->philo[i].left_fork, NULL);
		pthread_mutex_init(&params->philo[i].message, NULL);
		i++;
	}
}

int main(int argc, char **argv)
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
