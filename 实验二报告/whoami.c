#define __LIBRARY__
#include "unistd.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
_syscall2(int,whoami,char*,name,unsigned int,size)
int main(int argc,char *argv[])
{
	char *username;
	username=(char *)malloc(sizeof(char)*128);
	whoami(username,128);
	printf("%s\n",username);
	free(username);
	return 0;
}
