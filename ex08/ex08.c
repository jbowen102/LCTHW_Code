#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;

	if (argc == 1) {
		printf("You have no arguments.\n");
	}
	else if (argc == 2) {
		printf("You only have one argument. You suck.\n");
	} else if (argc > 2 && argc < 5) {
		printf("Here's your arguments:\n");

		for (i=1; i < argc; i++) {
			printf("%s ", argv[i]);
		}
		printf("\n");
	// } else if (argc == 5) {
	// 	printf("Four arguments.\n");
	// } else if (1) {
	// 	printf("text\n");
	} else {
		printf("You have too many arguments. You suck.\n");
	}

	return 0;
}
