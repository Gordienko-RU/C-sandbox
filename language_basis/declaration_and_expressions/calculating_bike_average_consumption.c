#include <stdio.h>

int main() {
  int distance;
  float spent;

  printf("distance:");
  scanf("%d", &distance);

  printf("how much spent:");
  scanf("%f", &spent);

  printf("total - %.3f /n", spent / distance);

  return 0;
}
