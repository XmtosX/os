#include<pthread.h>
#include<stdio.h>
char s[20];

int pos;

int a, b;
long long int t;

void* cos(void *x)
{
	while(1)
	{
		if(a)
			continue;
		if(pos == 0)
		{
			a = 1;
			b = 0;
			continue;
		}
		printf("%c", s[pos]);
		pos--;
	}
	pthread_exit(NULL);
	return NULL;
}
void* prod(void *x)
{
	while(1)
	{
		if(b)
			continue;

		if(pos == 20)
		{
			b = 1;
			a = 0;
			printf("production done in %lld time\n", t++);
			continue;
		}
		s[pos] = pos+ 'a' ;
		pos++;
	}

	pthread_exit(NULL);
	return NULL;
}

int main()
{
	a = 1;
	pthread_t tProducer, tConsumer;
	pthread_create(&tProducer, NULL, prod, NULL);
	pthread_create(&tConsumer, NULL, cos, NULL);
	while(1);
	return 0;
    //it stopped at time 56064
}
