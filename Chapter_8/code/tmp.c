#include <stdio.h>

void foo() { puts("foo called and returned"); }

int main() {
  void (*p)();
  p = foo;
  p();
  return 0;
}