#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

const int CHILD_PROCESS_PID = 0;

void error(char *msg) {
  fprintf(stderr, "%s : %s\n", msg, strerror(errno));
  exit(1);
}

int main(int argc, char *argv[]) {
  char *text = argv[1];
  int fd[2];
  if (pipe(fd) == -1) {
    error("can't create pipe");
  }

  pid_t pid = fork();
  if (pid == -1) {
    error("can't fork process");
  }

  if (pid == CHILD_PROCESS_PID) {
    dup2(fd[1], 1);
    close(fd[0]);

    execlp("curl", "curl", text, NULL);
  }

  dup2(fd[0], 0);
  close(fd[1]);

  char line[255];
  fgets(line, 255, stdin);
  puts(line);

  return 0;
}