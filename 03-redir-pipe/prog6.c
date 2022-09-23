#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	puts("prog6 running");

	printf("PROCESS: pid=%d ; ppid=%d\n", 
		getpid(), getppid()
	);

	pid_t pid = fork();
	if (pid == 0) {
		printf("CHILD: pid=%d ; ppid=%d\n", 
			getpid(), getppid()
		);

		int ofd = open("out.txt", O_CREAT | O_WRONLY, 0640);
		if (ofd == -1) {
			perror("open out.txt failed");
			exit(1);
		}

		dup2(ofd, 1);
		close(ofd);

		puts("CHILD: == REDIRECTED OUTPUT ==");
		puts("CHILD: hello, world!");


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
