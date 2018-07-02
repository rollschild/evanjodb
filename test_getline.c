#include <stdio.h>
#include <stdlib.h>

int main() {
  char* test_char;
  size_t size = 255;
  test_char = (char*)malloc(size * sizeof(char));
  ssize_t num = getline(&test_char, &size, stdin);
  printf("%s\n", test_char);
  printf("%d\n", sizeof(test_char));
  printf("%d\n", num);

  return 0;
}
