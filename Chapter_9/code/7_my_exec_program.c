#include <stddef.h>
#include <unistd.h>

int main() {
  char *my_env[] = {"JUICE=peach and apply", NULL};
  execle("7_diner_info", "7_diner_info", "4", NULL, my_env);
}