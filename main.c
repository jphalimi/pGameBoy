#include <stdio.h>
#include <stdlib.h>
#include "log/log.h"

int main (int argc, char *argv[])
{
	Log_setOutput (stderr);
	Log_setVerbosity (0);
	
	Log_output (1, "Welcome to the GameboyLight project. This is the first compilable version to be pushed ! Enjoy it ! :o)\n");
	
	(void) argc;
	(void) argv;
	return 0;
}
