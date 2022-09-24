#include <stdio.h>

// defining union
typedef union {
  short count;
  float weight;
  float volume;
} quantity;

// defining struct with the above union
typedef struct {
  const char *name;
  const char *country;
  quantity amount;
} fruit_order;

int main() {
  // declaring and initializing the struct
  fruit_order apples = {
      .name = "apples", .country = "England", .amount.weight = 4.2};

  printf("This order contains %2.2f lbs of %s\n", apples.amount.weight,
         apples.name);

  return 0;
}