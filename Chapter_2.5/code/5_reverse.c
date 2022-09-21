#include <stdio.h>
#include <string.h>

void print_reverse(char *s)
{
  size_t len = strlen(s);
  char *t = s + len - 1;

  while (t >= s)
  {
    printf("%c", *t);
    t--;
  }
  puts("");
}

int main()
{
  char *s = "hello";
  // char s[] = "hello";
  print_reverse(s);
}