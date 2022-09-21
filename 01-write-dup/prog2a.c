#include <stdio.h>
#include <unistd.h>
#include <errno.h>

// RUN:
//   ./prog1
//   ./prog1 3> abc.txt
//
int main() {
	write(1, "prog2a running\n", 15);

	int nfd = dup(1);

	int res1 = write(nfd, "hello, world\n", 13);
	if (res1 == -1) {
		perror("write to nfd failed");
	} else {
		puts("write to nfd succeeded");
	}

	int res2 = write(3, "hello, world\n", 13);
	if (res2 == -1) {
		perror("write to 3 failed");
	} else {
		puts("write to 3 succeeded");
	}

	puts("DONE");
	return 0;
}
