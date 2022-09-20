#include <stdio.h>
int y = 0;

int main()
{
  int x = 1;
  printf("x is stored at: %p\n", &x);
  printf("y is stored at: %p\n", &y);

  return 0;
}