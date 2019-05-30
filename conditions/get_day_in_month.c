#include <stdio.h>
#include <time.h>

int main() {
  int monthNumber;
  time_t s = time(NULL);
  struct tm *currentTime = localtime(&s);

  printf("%d", (currentTime->tm_year));
  printf("insert month index");
  scanf("%d", &monthNumber);

  // if (monthNumber == 2 && currentTime->tm_yday) {
  //   printf("case");
  // }

  return 0;
}