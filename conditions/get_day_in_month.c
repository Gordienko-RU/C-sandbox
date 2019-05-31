#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int getDaysCount(int, int);

int main() {
  int monthNumber, dayCount;
  time_t s = time(NULL);
  struct tm *currentTime = localtime(&s);
  const int currentYear = currentTime->tm_year + 1900;

  printf("insert month index \n");
  scanf("%d", &monthNumber);

  printf("\n day count - %d", getDaysCount(monthNumber, currentYear));

  return 0;
}

int getDaysCount(int monthNumber, int currentYear) {
    switch (monthNumber) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    case 4:
    case 6:
    case 9:
    case 11: 
      return 30;
    case 2: {
      bool isLeap = (currentYear % 100 == 0)
        ? (currentYear % 400 == 0)
        : (currentYear % 4 == 0);
      return isLeap ? 29 : 28;
    }
    default: 
      return 0;
  }
}
