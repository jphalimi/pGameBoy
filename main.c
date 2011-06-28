#include <stdio.h>
#include <stdlib.h>
#include "log/log.h"

int main (int argc, char *argv[])
{
	SLog *log;
	
	if (Log_create (&log) == -1)
	{
		fprintf (stderr, "Error: Cannot create log\n");
		exit (EXIT_FAILURE);
	}
	
	Log_setOutput (log, stderr);
	Log_setVerbosity (log, 0);
	
	Log_output (log, 1, "Welcome to the GameboyLight project. This is the first compilable version to be pushed ! Enjoy it ! :o)\n");
	
	Log_destroy (log), log = NULL;
	
	(void) argc;
	(void) argv;
	return 0;
}
