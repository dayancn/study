#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void handler(int sig)
{
	printf("process alarm signal %d.\n", sig);
}

int main(int argc, const char *argv[])
{
	int i;

	signal(SIGALRM, handler);
	alarm(3);
	/*pause();*/

	for (i=0; i<5; i++) {
		printf("sleep %d ...\n",i);
		sleep(1);
	}

	return 0;
}

