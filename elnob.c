#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

#define ELNOB_IMPLEMENTATION
#include "elnob.h"

// NOTE, we get away with wait(NULL) because we make sure that we do not fork
// more than once, a more secure function would be better

;
int main()
{
	struct stat code_stat;
	struct stat exec_stat;
	stat("elnob.c", &code_stat);
	stat("elnob.out", &exec_stat);

	pid_t pid;

	if (code_stat.st_mtime > exec_stat.st_mtime)
	{
		printf("elnob.c edited, need to recompile\n");
		const char * compile[] = {"gcc", "-o", "elnob.out", "elnob.c", NULL};
		run_command(4, compile);

		const char * rerun[] = {"./elnob.out", NULL};
		run_command(1,  rerun);
		/*
		pid = fork();
		if (pid == 0)
		{
			int r = execlp("gcc", "gcc", "-o","elnob.out",
					"elnob.c", NULL);
			printf("%d\n", r);
			return r;
		}
		wait(NULL);
		printf("Rerunning elnob\n");
		int r = execlp("./elnob.out", "./elnob.out", NULL);
		printf("%d\n", r);
		*/
		return 0;
	}
	const char * cmd[] = {"ls", "-a", NULL};
	run_command(2, cmd);
	return 0;
}
