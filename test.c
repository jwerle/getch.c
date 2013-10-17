
#include "getch.h"

int
main (void) {
  int c;
  while ((c = getch()) != EOF) {
    printf("c = %c\n", c);
  }
  return 0;
}
