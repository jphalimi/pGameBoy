#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>
#include "log.h"

static SLog log = {NULL, 0};

void Log_setOutput (FILE *fd)
{
	assert (fd != NULL);
	log.fd = fd;
}

void Log_setVerbosity (int verbosity)
{
	log.verbosity = verbosity;
}

int Log_output (int verbosity, const char *fmt, ...)
{
	assert (fmt != NULL);
	assert (log.fd != NULL);
	
	va_list va;
	int res = 0;
	
	if (log.verbosity < verbosity)
	{
		va_start (va, fmt);
		res = fprintf (log.fd, fmt, va);
		va_end (va);
	}
	
	return res;
}

int Log_flush (void)
{
	assert (log.fd != NULL);
	return fflush (log.fd);
}
