#include <stdio.h>
#include <ctype.h>
#include <string.h>

// forward declarations
int can_print_it(char ch);
void print_letters(char arg[], int arg_len);

void print_arguments(int argc, char *argv[])
{
	int i = 0;
	int arg_len = 0;

	for ( i=0 ; i<argc ; i++) {
		arg_len = strlen(argv[i]);
		// printf("Arg_len: %d\n", arg_len)/;
		print_letters(argv[i], arg_len);
	}
}

void print_letters(char arg[], int arg_len) {

	int i = 0;

	for ( i=0 ; i < arg_len ; i++ ) {
		char ch = arg[i];

		if (can_print_it(ch)) {
			printf("'%c' == %d ", ch, ch);
		}
	}

	printf("\n");
}

int can_print_it(char ch)
{
	return isdigit((int)ch) || isblank((int)ch);
}

int main(int argc, char *argv[])
{
	print_arguments(argc, argv);
	return 0;
}
