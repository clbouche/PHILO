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

<h2>Organisation</h2>

__ETAPE 1__



<h3>RESSOURCES</h3>
- https://www.youtube.com/watch?v=uA8X5zNOGw8&list=PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM&index=2
- https://www.youtube.com/watch?v=o_GbRujGCnM
- https://hpc-tutorials.llnl.gov/posix/  

