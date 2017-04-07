#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "errno.h"

#define BUF_SIZE        0x100000
#define BUF_MAX_NUM     256


int main(int argc, const char *argv[])
{
	char *p = NULL;
	int i=0;

	for (i=0; i<BUF_MAX_NUM; i++)
	{
		p = (char *) malloc (BUF_SIZE);
		if (p) {
			memset(p, 0, BUF_SIZE);
			printf("malloc [%d][%08x] success!\n", i+1, BUF_SIZE);
		} else {
			printf("==> malloc [%d][%08x] failed!\n", i+1, BUF_SIZE);
			break;
		}

		p=NULL;
	}

	return 0;
}
