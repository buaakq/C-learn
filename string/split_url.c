#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_and(char *valuekey)
{
	int ret = 0;
	while(*valuekey != '\0')
	{
		valuekey = strchr(valuekey, '&');
		if (valuekey == NULL)
			return ret;
		valuekey += 1;
		ret += 1;
	}
	return ret;
}

int my_split(char *url, char ***buf)
{
	int n = count_and(url);
	n += 1;
	printf("There are %d key_value pairs.\n", n);

	*buf = (char **)malloc((n+1)*sizeof(char *));
	
	char *save;
	char *token;
	token = strtok_r(url, "&", &save);
	
	(*buf)[0] = token;
	for(int i = 1; i < n; i ++)
	{
		token = strtok_r(NULL, "&", &save);
		(*buf)[i] = token;
	}

	return n;
}

void free_split(char **buf)
{
	free(buf);
}
	
int main(int argc, char *argv[])
{
	char *url = argv[1];

	char **buf;
	char *start = strchr(url, '?');
    int n = my_split(start+1, &buf);
	for(int i = 0; i < n; i++)
	{
		printf("No. %d key_value is %s\n", i, buf[i]);
	}

	free_split(buf);

	return 0;
}

