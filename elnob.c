#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

int main()
{
	printf("Hello Elnob\n");
	pid_t pid = fork();

	if (pid == 0)
	{
		int result = execlp("gcc", "gcc", "-Wall", "-Wextra", "-o", "elnob", "elnob.c", NULL);
		if (result < 0) { printf("Failed to run command\n"); return 1; }
		return 0;
	} else
	{
		wait(NULL);2
		printf("I want this to run as well\n");
	}

	return 0;
}
