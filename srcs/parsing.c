/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:16:47 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/10 13:35:14 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	recup_args(int argc, char **argv)
{
	t_thread_data	*data;
	t_philo			*philo;

	//check si 5 ou 6 arg
	//si 5, set a 0 nb_meals_per_philo
	//else : recup le dernier arg 
	//passer dans tous les cas par la recup des autres args
	//data->nb_of_philo = atoi(argv[1]);
}