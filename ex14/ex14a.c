#include <stdio.h>
#include <ctype.h>

// forward declarations

int main(int argc, char *argv[])
{
	int i = 0;

	for ( i=0 ; i<argc ; i++) {

		int j = 0;

		for (j=0 ; argv[i][j] != '\0' ; j++ ) {
			if (isalpha((int)argv[i][j]) || isblank((int)argv[i][j])) {
				printf("'%c' == %d ", argv[i][j], argv[i][j]);
			}
		}
		printf("\n");

	}
return 0;
}
