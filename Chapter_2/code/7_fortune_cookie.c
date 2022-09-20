#include <stdio.h>

void fortune_cookie(char msg[])
{
  printf("Message reads: %s\n", msg);
  printf("The msg is stored at: %p\n", msg);
  printf("The character at above location is: %c\n", *msg);
}

int main()
{
  char quote[] = "Cookies make you fat";
  fortune_cookie(quote);

  return 0;
}