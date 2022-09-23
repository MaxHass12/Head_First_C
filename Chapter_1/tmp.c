#include <stdio.h>
#include <string.h>

int main() {
  char *names[] = {"foo", "bar", "baz"};
  printf("sizeof(names[0]) : %lu\n", sizeof(*names[0]));
  return 0;
}
