#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 24;
	while (i >= 0) {
		printf("%d", i);
		i--;
	}

	// need this to add a final new line.
	printf("\n");

	return 0;
}
