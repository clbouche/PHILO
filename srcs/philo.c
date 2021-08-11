/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:01:18 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/11 15:06:50 by clbouche         ###   ########.fr       */
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
		i++;
	}
}

int main(int argc, char **argv)
{
	t_params	params;
	int			i;

	i = 0;
	recup_args(argc, argv, &params);
	initialisation(&params);
	create_threads(&params);
	free(params.philo);
	return (0);
}


//gerer avec arg 6 pour ne pas avoir a gerer la mort dans un premier temps 
//tous les philos pensent en premier 
//faire en sorte qu'un philo sur 2 mangent 
//faire penser les autres
//faire dormir ceux qui ont manges 
//passer les fourchettes aux suivants 


//se pencher sur la gestion du temps, comprendre 

//determiner comment controler la mort 
//la verifier a chaque changement d'etat pour etre sure de ne pas depasser 10ms ?
//les philos ne parlent pas entre eux et ne savent pas si un autre philo est EN TRAIN de mourir 
// MAIS peuvent etre informes lorsqu'un philo est mort