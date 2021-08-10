/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:25:49 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/10 15:49:25 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

typedef	struct              s_p
{
    pthread_mutex_t         mutex;
    int                     thread_id;
}                           t_p;

void    *function(void *pp)
{
    char *str;
    int i;
	int	nb_of_thread;
    t_p *ppp;

	i = 0;
    str = "thread 1 : coucou ca va ? \n";
    ppp = (t_p *)pp;
	nb_of_thread = ppp->thread_id;
    pthread_mutex_lock(&ppp->mutex); // si on enleve ici
	printf("Thread %d: \n", nb_of_thread);
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    pthread_mutex_unlock(&ppp->mutex); // si on enleve ici
    return (NULL);
}

int main()
{
    pthread_t               thread_id[3];
    //pthread_t               thread_id2;
    int		t;
	t_p                     *thread_data;

	t = 0;
	while(t < 3)
	{
		thread_data->thread_id = t;
		pthread_mutex_init(&thread_data->mutex, NULL);			// obligatoire de init le mutex
		pthread_create(&thread_id[t], NULL, function, (void *)&thread_data);
		t++;
	}
		sleep(1);
}

//faire la meme chose mais avec des datas qui se partage entre les threads (les args?)