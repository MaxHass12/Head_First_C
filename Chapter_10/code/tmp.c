#include <stdio.h>
#include <unistd.h>

int main() {
  puts("before forking");
  printf("pid : %d\n", getpid());
  pid_t pid = fork();
  if (pid == 0) {
    puts("\tIn child process");
    printf("\tpid : %d\n", getpid());
  } else {
    puts("\tIn Parent process");
    printf("\tpid : %d\n", getpid());
  }
}