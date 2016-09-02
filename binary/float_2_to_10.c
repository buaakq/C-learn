#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *dest) {
	if (dest == '\0')
		return ;
	char *lo = dest;
	char *hi = dest;
	while(*hi != '\0') {
		hi ++;
	}
	hi --;

	while (lo < hi) {
		char temp = *lo;
		*lo = *hi;
		*hi = temp;
		lo ++;
		hi --;
	}
}

void two_to_ten(char *str, char *buf) {
	char *start = str;
	char *point = str;
	while (*point != '.' && *point != '\0')
		point ++;
	if (point == '\0')
		//return convert_i(str, buf);
		return; 
	char * part1 = malloc((point-start) * sizeof(char));
	strncpy(part1, str, point-start);
	char * part2 = malloc((strlen(point)+1) * sizeof(char));
    strcpy(part2 + 1, point);
	*part2 = '0';
	
	int zheng = atoi(part1);
	double d = atof(part2);

	char *dest = buf;
	while(zheng)
	{
		*dest = zheng % 2 + '0';
		zheng /= 2;
		dest ++;
	}
	*dest = '\0';
	reverse(buf);
	*dest = '.';
	dest ++;
	int loop = 10;
	while(loop --) {
		d *= 2;
		int a = (int)d;
		if (d >= 1)
			d -= 1;
		*dest = a + '0';
		dest ++;
	}
	*dest = '\0';
}


int main(int argc, char ** argv) {
	if(argc != 2) {
		printf("Wrong args, will exit\n");
		exit(1);
	}

	char * str = argv[1];
	printf("input is %s\n", str);

    char buf[1000];
	two_to_ten(str, buf);
	printf("10 float is %s\n", buf);
}
		
