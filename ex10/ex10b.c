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

    switch (letter) {
      case 'A':
        printf("%d: 'A'\n", i);
        break;

      case 'E':
        printf("%d: 'E'\n", i);
        break;

      case 'I':
        printf("%d: 'I'\n", i);
        break;

      case 'O':
        printf("%d: 'O'\n", i);
        break;

      case 'U':
        printf("%d: 'U'\n", i);
        break;

      case 'Y':
        if (i > 2) {
          printf("%d: 'Y'\n", i);
          break;
        }

      default:
        printf("%d: %c is not a vowel\n", i, letter);
    }
  }

  return 0;
}
