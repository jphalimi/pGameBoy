#ifndef H_LOG
#define H_LOG

typedef struct sLog
{
	FILE *fd;
	int verbosity;
} SLog;

void Log_setOutput (FILE *fd);
void Log_setVerbosity (int verbosity);
int Log_output (int verbosity, const char *fmt, ...);
int Log_flush ();

#endif
