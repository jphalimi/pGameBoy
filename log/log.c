#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>
#include "log.h"

int Log_create (SLog **log)
{
	/* In case the log struct is already allocated */
	free (*log), *log = NULL;
	
	/* Let's malloc ! :-) */
	*log = malloc (sizeof(**log));
	
	if (*log == NULL)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

void Log_setOutput (SLog *log, FILE *fd)
{
	assert (log != NULL);
	assert (fd != NULL);
	log->fd = fd;
}

void Log_setVerbosity (SLog *log, int verbosity)
{
	assert (log != NULL);
	log->verbosity = verbosity;
}

int Log_output (const SLog *log, int verbosity, const char *fmt, ...)
{
	
	assert (log != NULL);
	assert (fmt != NULL);
	
	va_list va;
	int res = 0;
	
	if (log->verbosity < verbosity)
	{
		va_start (va, fmt);
		res = fprintf (log->fd, fmt, va);
		va_end (va);
	}
	
	return res;
}

void Log_destroy (SLog *log)
{
	assert (log != NULL);
	free (log), log = NULL;
}
