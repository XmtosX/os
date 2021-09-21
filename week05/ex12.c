#include<stdlib.h>
#include<pthread.h>
#include<stdio.h>
pthread_mutex_t L;
void* print(void* id)
{
	pthread_mutex_lock(&L);
	int t = (int)id;
	printf("thread number %d is created.\n", t);
	printf("thread #%d\n", t);
	pthread_mutex_unlock(&L);
	pthread_exit(NULL);
	return NULL;
}
int main()
{
	pthread_t TH[15];
	int th;
	if(pthread_mutex_init(&L, NULL) != 0)
	{
		printf("creating mutex failed\n");
		exit(-1);
	}
	for (int i = 0; i < 15; i++)
	{
		th = pthread_create(&TH[i], NULL, print, (void*)i);
		if (th!=0)
		{
			printf("error in creating thread #%d", i);
			exit(-1);
		}
	}
	pthread_mutex_destroy(&L);
	pthread_exit(NULL);
	return 0;
}
