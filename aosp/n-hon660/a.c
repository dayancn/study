#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, const char *argv[])
{
	char p[2][8] = {"abc", "hhh"};

	strcpy(p[0], "hello");
	printf("%s\n", p[0]);

	return 0;
}
