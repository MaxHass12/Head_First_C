#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int catch_signal(int sig, void (*handler)(int)) {
  struct sigaction action;
  action.sa_handler = handler;
  sigemptyset(&action.sa_mask);
  action.sa_flags = 0;
  return sigaction(sig, &action, NULL);
}

void pour_coffee() { puts("coffee poured"); }

int main() {
  catch_signal(SIGALRM, pour_coffee);
  alarm(1);
  puts("Some important work.");
  return 0;
}