#include <stdio.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	char file[] = {"/etc/hosts"};
	char FILE[] = {"/etc/HOSTS"};
	char dir[] = {"/etc"};
	char DIR[] = {"/ETC"};

	if (!access(file, F_OK)) {
		printf("%s exist\n", file);
	} else {
		printf("%s doesn't exist\n", file);
	}

	if (!access(FILE, F_OK)) {
		printf("%s exist\n", FILE);
	} else {
		printf("%s doesn't exist\n", FILE);
	}

	if (!access(dir, F_OK)) {
		printf("%s exist\n", dir);
	} else {
		printf("%s doesn't exist\n", dir);
	}

	if (!access(DIR, F_OK)) {
		printf("%s exist\n", DIR);
	} else {
		printf("%s doesn't exist\n", DIR);
	}

	return 0;
}
