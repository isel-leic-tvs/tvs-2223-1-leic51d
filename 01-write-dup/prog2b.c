#include <stdio.h>
#include <unistd.h>

// RUN:
//   ./prog1
//   ./prog1 88> abc.txt
//
int main() {
	write(1, "prog2b running\n", 15);

	int nfd = dup2(1, 88);

	int res1 = write(nfd, "hello, world\n", 13);
	if (res1 == -1) {
		perror("write to nfd failed");
	} else {
		puts("write to nfd succeeded");
	}

	puts("DONE");
	return 0;
}
