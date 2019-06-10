#include <stdio.h>

int addByReference(int*, int*);

int main() {
  int var1, var2, summ;

  scanf("%d %d", &var1, &var2);
  summ = addByReference(&var1, &var2);
  printf("summ is %d", summ);

  return 0;
}

int addByReference(int *pnt1, int *pnt2) {
  return *pnt1 + *pnt2;
};