#include <stdio.h>
#include <sys/time.h>

int main(void)
{
	struct timeval		tv;
	unsigned long long	curtime;
	char				buffer[30];

	while (1)
	{
		gettimeofday(&tv, NULL);
		curtime = (unsigned long long)((tv.tv_sec * 1000000 + tv.tv_usec) / 1000);
		printf("time is: %llu\n", curtime);
	}
}
