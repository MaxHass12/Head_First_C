#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

const char *FILENAME = "file.txt";

void error(char *msg) {
  fprintf(stderr, "%s : %s\n", msg, strerror(errno));
  exit(1);
}

int main(int argc, char *argv[]) {
  char *msg = argv[1];
  FILE *f = fopen(FILENAME, "w");
  if (!f) {
    error("Can not open file.");
  }
  printf("pid before forking : %d\n", getpid());
  pid_t pid = fork();
  printf("after forking - pid : %d\n", pid);
  if (pid == -1) {
    error("Can not fork process.");
  }
  if (!pid) {
    if (dup2(fileno(f), 1) == -1) {
      error("Can't redirect Standard Output.");
    }
    system("sleep 3");
    execlp("echo", "echo", msg, NULL);
  }
  int pid_status;
  if (waitpid(pid, &pid_status, 0) == -1) {
    error("Error waiting for the child process");
  }
  printf("program over - pid : %d\n", pid);
  return 0;
}