/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:01:18 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/10 17:12:13 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    *routine()
{
    printf("ca marche");
    return (NULL);
}


int main(int argc, char **argv)
{
	t_philo				*philo;
    t_thread_data      data;

	recup_args(argc, argv, &data);
    /*while (i < args->number_of_philo)
        pthread_create(&philos[i++], NULL, routine, args);*/
}
