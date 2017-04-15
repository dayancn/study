#include <stdio.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	char dir[] = {"test"};

	if (mkdir(dir, 0755))
		perror("mkdir");

	return 0;
}
