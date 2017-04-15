#include <stdio.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	char dir[] = {"test"};

	if (rmdir(dir))
		perror("mkdir");

	return 0;
}
