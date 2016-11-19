#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int get_lines(FILE *file)
{
	int ret = 0;
	int error = fseek(file, 0, SEEK_SET);
	if (error != 0)
	{
		perror("fseek the file:");
		exit(3);
	}

	char buf[40];
	while(fgets(buf, 40, file) != NULL)
	{
		ret += 1;
	}
	return ret;
}

void format_time(char *buf, int n)
{
	time_t t;
	time(&t);
	struct tm *now;
	now = localtime(&t);

	sprintf(buf, "%d %d-%d-%d %d:%d:%d\n", n, now->tm_year, now->tm_mon, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);
}

void write_log(char *buf, FILE *file)
{
	int error = fseek(file, 0, SEEK_END);
	fputs(buf, file);
}

int main(int argc, char **argv)
{
	FILE *file;
	file = fopen("logfile", "a+");
	if (file == NULL)
	{
		perror("opening log file");
		exit(2);
	}

	int lines = get_lines(file);
	char buf[40] = "test long\n";

	while(1)
	{
		format_time(buf, lines+1);
		write_log(buf, file);
		printf("n is %d, buf is %s\n", lines+1, buf);
		fflush(stdout);
		fflush(file);
		sleep(1);
		lines++;
	}

	return 0;
}

