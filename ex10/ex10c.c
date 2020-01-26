#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("ERROR: You need one argument.\n");
    // This is how you abort a program.
    return 1;
  }

  int i = 0;
  char letter;
  for (i=0, letter=argv[1][i]; letter != '\0'; i++, letter=argv[1][i]) {

    if (letter >= 97 && letter <= 122) {
      letter -= 32;
    }


    if (letter == 'A') {
      printf("%d: 'A'\n", i);
    }
    else if (letter == 'E') {
      printf("%d: 'E'\n", i);
    }
    else if (letter == 'I') {
      printf("%d: 'I'\n", i);
    }
    else if (letter == 'O') {
      printf("%d: 'O'\n", i);
    }
    else if (letter == 'U') {
      printf("%d: 'U'\n", i);
    }
    else if (letter == 'U') {
      printf("%d: 'U'\n", i);
    }
    else if (letter == 'Y') {
      if (i > 2) {
        printf("%d: 'Y'\n", i);
      }
      else {
        printf("%d: %c is not a vowel\n", i, letter);
        }
    }
    else {
      printf("%d: %c is not a vowel\n", i, letter);
    }
  }

  return 0;
}
