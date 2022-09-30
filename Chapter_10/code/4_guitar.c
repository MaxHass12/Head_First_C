#include <stdio.h>

int main() {
  FILE *my_file = fopen("guitar.txt", "r");
  int descriptor = fileno(my_file);
  printf("descriptor : %i\n", descriptor);
  fclose(my_file);
  return 0;
}