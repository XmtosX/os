#include<stdlib.h>
#include<pthread.h>
#include<stdio.h>
void* print(void* id)
{
	int t = (int)id;
	printf("thread #%d\n", t);
	pthread_exit(NULL);
}
int main()
{
	pthread_t TH[15];
	int th;
	for (int i = 0; i < 15; i++)
	{
		printf("thread number %d is being created.\n", i);
		th = pthread_create(&TH[i], NULL, print, (void*)i);
		if (th!=0)
		{
			printf("error in creating thread #%d", i);
			exit(-1);
		}
	}
	pthread_exit(NULL);
	return 0;
}
