
#ifndef __GETCH_H__
#define __GETCH_H__ 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

int
getch ();

int
getch () {
  int c = EOF;
  struct termios term, ttmp;

  // get stdin attributes
  tcgetattr(STDIN_FILENO, &term);

  // store state of stdin
  ttmp = term;

  // canonical input and echo modes
  ttmp.c_lflag &= ~(ICANON|ECHO);

  // set stdin attributes on tmp termio struct now with `TCSANOW`
  tcsetattr(STDIN_FILENO, TCSANOW, &ttmp);

  // get char from modified stdin
  c = getchar();

  // reset stdin to previous state
  tcsetattr(STDIN_FILENO, TCSANOW, &term);

  return c;
}

#endif
