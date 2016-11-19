#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int get_curr_cout(FILE *log)
{
	return 1;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: ./a.out log-file\n");
		exit(2);
	}

	FILE *log;
	if((log = fopen(argv[1], "a") == NULL))
	{
		perror("open log file:");
		exit(3);
	}

	time_t cur;
	int counter = get_curr_cont(log);
	while(1)
	{
		if (time(&cur) == (time_t)-1)
		{
			perror("get time:");
			exit(4);
		}
		
		struct tm* ret = localtime(&cur);
		// test struct tm
		printf("%d %d-%d-%d %d-%d-%d\n", counter, ret->tm_year, ret->tm_mon, ret->tm_mday, ret->tm_hour, ret->tm_min, ret->tm_sec);
		sleep(1);
	}

	return 0;
}
		

	
		
