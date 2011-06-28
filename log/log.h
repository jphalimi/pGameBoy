#ifndef H_LOG
#define H_LOG

typedef struct sLog
{
	FILE *fd;
	int verbosity;
} SLog;

int Log_create (SLog **log);
void Log_setOutput (SLog *log, FILE *fd);
void Log_setVerbosity (SLog *log, int verbosity);
int Log_output (const SLog *log, int verbosity, const char *fmt, ...);
int Log_flush (const SLog *log);
void Log_destroy (SLog *log);

#endif
