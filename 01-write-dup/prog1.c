#include <stdio.h>
#include <unistd.h>

// RUN:
//   ./prog1
//   ./prog1 3> abc.txt
//
int main() {
	write(1, "prog1 running\n", 14);

	int res = write(3, "hello, world\n", 13);
	if (res == -1) {
		perror("write to 3 failed");
	} else {
		puts("write succeeded");
	}

	puts("DONE");
	return 0;
}
