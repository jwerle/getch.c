
#ifndef GETCH_H
#define GETCH_H 1

#include <signal.h>

int
getch (void);

static void
on_signal (int);

static int signals[] = {
  SIGABRT,
  SIGINT,
  SIGKILL,
  SIGQUIT,
  SIGSTOP,
  SIGTERM
};

#endif
