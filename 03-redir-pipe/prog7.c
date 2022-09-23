#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	puts("prog7 running");

	int pipefd[2];
	pipe(pipefd);
	
	/*
	write(pipefd[1], "hello, world!", 13);
	
	sleep(5);
	
	char msg[14];
	int n = read(pipefd[0], msg, 13);
	msg[n] = 0;
	
	puts(msg);
	*/
	
	pid_t pid = fork();
	if (pid == 0) {
		close(pipefd[0]);

		write(pipefd[1], "hello, world!\n", 14);
		sleep(3);
		write(pipefd[1], "hello, isel!\n", 13);
		sleep(3);
		write(pipefd[1], "hello, leic51d!\n", 16);

		close(pipefd[1]);
	} else {
		close(pipefd[1]);

		for (;;) {
			char msg[256];
			int n = read(pipefd[0], msg, 255);
			if (n == 0) break;
			
			msg[n] = 0;
			printf("[msg] %s\n", msg); 
		}

		close(pipefd[0]);
	}
}
