#include <stdio.h>
#include <stdlib.h>

void usage(const char *pgm) {
  printf("%s <num>\n", pgm);
  exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    usage(argv[0]);
  }

  int n = atoi(argv[1]);
  int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100};
  char *sym[] = {"I", "IV", "V", "IX", "X", "XL", "L", "LC", "C"};

  int i = sizeof(num)/sizeof(num[0]) - 1;
  while(n > 0) {
    int div = n/num[i];
    while(div--) {
      printf("%s", sym[i]);
    }
    n = n % num[i];
    i--;
  }
  exit(EXIT_SUCCESS);
}
