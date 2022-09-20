#include <stdio.h>

int main()
{
  char *str1 = "foo";
  char str2[] = "bar";

  str1 = str2;

  printf("str1 = %s\n", str1);
  printf("str2 = %s\n", str2);

  return 0;
}