#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	puts("prog5 running");

	printf("PROCESS: pid=%d ; ppid=%d\n", 
		getpid(), getppid()
	);

	pid_t pid = fork();
	if (pid == 0) {
		printf("CHILD: pid=%d ; ppid=%d\n", 
			getpid(), getppid()
		);

		puts("CHILD: exec...");
		execlp("./prog2b", "prog2b", NULL);

		puts(
			"=======================\n"
			"EXEC FAILED\n"
			"-----------------------\n"
			"IF YOU SEE THIS MESSAGE, YOU MUST COMPILE prog2b.c\n"
			"AND THEN COPY prog2b INTO THIS DIRECTORY\n" 
			"======================="
		);

	} else {
		printf("PARENT: pid=%d ; ppid=%d\n", 
			getpid(), getppid()
		);
		int res = 0;
		waitpid(pid, &res, 0);
		if (WIFEXITED(res)) {
			printf("PARENT: child returned %d\n", 
				WEXITSTATUS(res)
			);
		} else {
			printf("PARENT: child terminated\n"); 
		}
	}

	puts("THE END");
	return 0;
}
