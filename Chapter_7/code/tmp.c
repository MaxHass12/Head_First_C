#include <stdio.h>

int SCORES[] = {543, 323, 32, 554, 11, 3, 112};
int SCORES_LEN = 7;

int compare_scores(const void *score_a, const void *score_b) {
  int a = *(int *)score_a;
  int b = *(int *)score_b;
  return a - b;
}

void print_scores() {
  for (int i = 0; i < SCORES_LEN; i++) {
    printf("%i\n", SCORES[i]);
  }
}

// int main() {
//   print_scores();
//   qsort(SCORES, 7, sizeof(int), compare_scores);
//   puts("sorting...");
//   print_scores();
//   return 0;
// }