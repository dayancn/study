#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define TRUE    1
#define FALSE   0

static int list_dir(char *path)
{
	DIR     *dir = NULL;
	struct dirent *ptr;
	struct stat st;
	char file[1024];

	dir = opendir(path);
	if (!dir) {
		perror(path);
		return FALSE;
	}

	while ((ptr=readdir(dir)) != NULL) {
		if (!strcmp(".", basename(ptr->d_name)) || !strcmp("..", basename(ptr->d_name))) {
			continue;
		}

		sprintf(file, "%s/%s", path, ptr->d_name);
		lstat(file, &st);
		if (S_ISDIR(st.st_mode)) {
			printf("dir:%s\n", file);
			list_dir(file);
		} else if (S_ISREG(st.st_mode)) {
			printf("file:%s\n", file);
		}
	}

	return 0;
}

int main(int argc, const char *argv[])
{
	list_dir("~");
	list_dir("/tmp");

	return 0;
}
