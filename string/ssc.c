#include <stdio.h>
#include <stdlib.h>

int main()
{
	char gesture[3][20] = {"scissor", "stone", "clothes"};
	int user;
	while(1)
	{
		printf("Pls. input your choice and press enter\n");
		int error = scanf("%d", &user);

		if (error == EOF){
			printf("will exit\n");
			exit(0);
		}

		if (user > 2 || user < 0){
			printf("Invalid input, again\n");
			continue;
		}

		int sys = rand() % 3;
		printf("Your guess is %s,\ncomputer guess is %s\n", gesture[user], gesture[sys]);

		int ret = (user-sys+4) %3 - 1;
		if (ret == 0)
			printf("Fair!\n");
		else if(ret > 0)
			printf("Win!\n");
		else
			printf("Lost!\n");
	}	
	return 0;
}
