#include <stdio.h>
#include <stdlib.h>

int main()
{
  int val = -1;

  if (val)
  {
    puts("truthy");
  }
  else
  {
    puts("falsey");
  }

  return 0;
}