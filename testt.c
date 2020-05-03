#include <stdio.h>

int main(int argc, char const *argv[]) {
  char str[10];

  str[0] = 'a';
  str[1] = 'b';
  str[2] = 1;
  str[3] = 'a';
  str[4] = 0;
  printf("%s", str);
  return 0;
}
