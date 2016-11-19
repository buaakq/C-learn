#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strtok_r(char *str, const char *delim, char **save_ptr)
{
	char *token;

	if (!str)
		str = *save_ptr;

	if (*str == '\0')
		return NULL;

	int num = strspn(str, delim);
	str += num;

	if (*str == '\0')
		return NULL;

    token = str;
	str = strpbrk(token, delim);
	if (str == NULL)
		*save_ptr = strchr(token, '\0');
	else
	{
		*str = '\0';
		*save_ptr = str + 1;
	}

	return token;
}

int main(int argc,  char *argv[])
{
	if (argc != 4)
	{
		fprintf(stderr, "usage :%s str delim subdelim\n", argv[0]);
		exit(1);
	}

	char *str = argv[1];
	char *delim = argv[2];
	char *subdelim = argv[3];

	char *pos1, *pos2;
	char *token, *subtoken;

	int i = 1;
	while(1)
	{
		token = my_strtok_r(str, delim, &pos1);
		if (token == NULL)
			break;
		printf("%d: %s\n", i, token);
		str = NULL;

		while(1)
		{
			subtoken = my_strtok_r(token, subdelim, &pos2);
			if (subtoken == NULL)
				break;
			printf("    %s\n", subtoken);
			token = NULL;
		}
		
		i += 1;
	}
	
	return 0;
}
