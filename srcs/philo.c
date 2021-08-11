/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:01:18 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/11 14:16:26 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


int main(int argc, char **argv)
{
	t_params	params;
	int			i;

	i = 0;
	recup_args(argc, argv, &params);
	create_threads(&params);
}

//malloc le nbre de philos

//creer le nombre de thread qui correspond au nombre de philo

//gerer avec arg 6 pour ne pas avoir a gerer la mort dans un premier temps 
//tous les philos pensent en premier 
//faire en sorte qu'un philo sur 2 mangent 
//faire penser les autres
//faire dormir ceux qui ont manges 
//passer les fourchettes aux suivants 


//se pencher sur la gestion du temps, comprendre 

//determiner comment controler la mort 
//la verifier a chaque changement d'etat pour etre sure de ne pas depasser 10ms ? 