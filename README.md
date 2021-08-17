# philosophers

<h2>Comprendre les threads</h2>

```
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

typedef struct s_thread_data
{
	int		thread_id;
	char	*message;
}				t_thread_data;

void	*function(void *thread_data)
{	
	char *hello_msg;
	int	nb_of_thread;
	t_thread_data *data;

	usleep(1);
	data = (t_thread_data *)thread_data;
	nb_of_thread = data->thread_id;
	hello_msg = data->message;
	printf("Thread %d: %s  \n", nb_of_thread, hello_msg);
	return (NULL);
}

int main()
{
	pthread_t	threads[3];
	t_thread_data		thread_data[3];
	int 		t;
	char 		*messages[3];

	t = 0;
	messages[0] = "English: Hello World!";
	messages[1] = "French: Bonjour, le monde!";
	messages[2] = "¡Spanish: Hola todos!";
	while(t < 3)
	{
		printf("Creating thread %d\n", t);
		thread_data[t].thread_id = t;
  		thread_data[t].message = messages[t];
		pthread_create(&threads[t], NULL, function, (void *)&thread_data[t]);
		pthread_join(threads[t], NULL);
		t++;
	}
}
```

<h2>Comprendre les mutex</h2>
```
```

<h2>Projet</h2>

__INITIALISATION__

- chaque philo doit avoir 2 fourchettes : 
	- sa fourchette de gauche 
	- la fourchette a droite : pointeur sur la fourchette de gauche de son voisin de droite 
- mutex init :
	- un mutex pour afficher le message pour eviter scrambled
	- un mutex pour la fourchette de gauche
	- un mutex pour la fourchette de droite 

__LANCEMENT__

- creer d'abord les threads des philos pairs (s'affiche comme impair car l'id des philos est i + 1)
- creer ensuite les threads des philos impairs
	-> permet d'eviter que chaque philo ait la fourchette de gauche sans pouvoir prendre celle de droite

__COMPORTEMENTS DE BASE__
- MANGER 
	- bloquer l'obtention de la fourchette de gauche jusqu'a avoir termine de manger
	- bloquer la fourchette de droite a l'identique
	- afficher les 3 messages
	- usleep 
- DORMIR
	- afficher le message
	- usleep 
- PENSER
	- afficher le message 

__GESTION DU TEMPS__
//comment est recupere le temps par la fonction gettimeofday 
//recuperer le temps de depart
//convertir en temps affichable comme le projet le demande = millisecondes
//afficher le moment ou l'action est faites en soustrayant le temps de depart du temps actuel + operations = affichage en millisecondes 

__MORT D'UN PHILO__
- besoin de checker sa mort : 
	- timer qui demarre apres avoir termine de manger 
	- et qui se reinitialise a chaque fois
	- si le temps actuel == time_to_die = mort 
- besoin d'arreter le programme : 
	- thread de mort qui check en continue la mort d'un philo 

<h3>RESSOURCES</h3>
- https://www.youtube.com/watch?v=uA8X5zNOGw8&list=PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM&index=2
- https://www.youtube.com/watch?v=o_GbRujGCnM
- https://hpc-tutorials.llnl.gov/posix/  

