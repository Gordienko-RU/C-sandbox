#include <stdio.h>
#include <time.h>

int main() {
  int monthNumber;
  time_t s = time(NULL);
  struct tm *currentTime = localtime(&s);

  printf("insert month index");
  scanf("%d", &monthNumber);

  s = time(NULL);


  if (monthNumber == 2 && (localtime(&(time(NULL)))).tm_yday) {

  }
}