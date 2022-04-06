#include <stdio.h>

int main() {
   const char greeting[] = "Hello world";

   printf("%p\n", &greeting);
   printf("%p\n", (&greeting + 1000));

   printf("%s\n", greeting);
   return 0;
};
