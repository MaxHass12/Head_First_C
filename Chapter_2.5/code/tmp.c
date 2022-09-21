#include <stdio.h>
#include <string.h>

int main()
{
  char *strings[] = {"foo", "bar", "baz"};

  printf("strings[0] : %p\n", *strings);
  printf("strings[1] : %p\n", *(strings + 1));
  printf("strings[2] : %p\n", *(strings + 2));

  printf("strings[0] : %s\n", *strings);
  printf("strings[1] : %s\n", *(strings + 1));
  printf("strings[2] : %s\n", *(strings + 2));

  return 0;
}