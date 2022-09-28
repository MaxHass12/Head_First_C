#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  if (execl("/sbin/ifconfig1", "sbin/ifconfig1", NULL) == -1) {
    if (execlp("ipconfig1", "ipconfig1", NULL) == -1) {
      fprintf(stderr, "Cannot run ipconfig: %s", strerror(errno));
      return 1;
    }
  }
  return 0;
}