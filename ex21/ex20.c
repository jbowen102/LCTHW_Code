#include <stdint.h>
#include <stdio.h>


int main(int argc, char *argv[])
{

	printf("\n\t uint8_t\n");
	printf("Biggest 8-bit unsigned int: %d\n", UINT8_MAX);

	uint8_t my_num1 = UINT8_MAX-5;
	while (my_num1 > 0) {
		printf("This is an 8-bit unsigned int: %d\n", my_num1);
		my_num1++;
	}


	printf("\n\t int8_t\n");
	printf("Biggest 8-bit signed int: %d\n", INT8_MAX);
	printf("Smallest 8-bit signed int: %d\n", INT8_MIN);

	int8_t my_num2 = INT8_MAX-5;
	while (my_num2 > 0) {
		printf("This is an 8-bit signed int: %d\n", my_num2);
		my_num2++;
	}
	my_num2 = INT8_MIN+5;
	while (my_num2 < 0) {
		printf("This is an 8-bit signed int: %d\n", my_num2);
		my_num2--;
	}


	printf("\n\t uint16_t\n");
	printf("Biggest 16-bit unsigned int: %d\n", UINT16_MAX);

	uint16_t my_num3 = UINT16_MAX-5;
	while (my_num3 > 0) {
		printf("This is an 16-bit unsigned int: %d\n", my_num3);
		my_num3++;
	}


	printf("\n\t int16_t\n");
	printf("Biggest 16-bit signed int: %d\n", INT16_MAX);
	printf("Smallest 16-bit signed int: %d\n", INT16_MIN);

	int16_t my_num4 = INT16_MAX-5;
	while (my_num4 > 0) {
		printf("This is a 16-bit signed int: %d\n", my_num4);
		my_num4++;
	}
	my_num4 = INT16_MIN+5;
	while (my_num4 < 0) {
		printf("This is a 16-bit signed int: %d\n", my_num4);
		my_num4--;
	}


	printf("\n\t uint32_t\n");
	printf("Biggest 32-bit unsigned int: %u\n",  UINT32_MAX);

	uint32_t my_num5 = UINT32_MAX-5;
	while (my_num5 > 0) {
		printf("This is a 32-bit unsigned int: %u\n", my_num5);
		my_num5++;
	}


	printf("\n\t int32_t\n");
	printf("Biggest 32-bit signed int: %i\n", INT32_MAX);
	printf("Smallest 32-bit signed int: %i\n", INT32_MIN);

	int32_t my_num6 = INT32_MAX - 5;
	while (my_num6 > 0) {
		printf("This is a 32-bit signed int: %i\n", my_num6);
		my_num6++;
	}
	my_num6 = INT32_MIN + 5;
	while (my_num6 < 0) {
		printf("This is a 32-bit signed int: %i\n", my_num6);
		my_num6--;
	}


	printf("\n\t uint64_t\n");
	printf("Biggest 64-bit unsigned int: %lu\n", UINT64_MAX);
	uint64_t my_num7 = UINT64_MAX - 5;
	while (my_num7 > 0) {
		printf("This is a 64-bit unsigned int: %lu\n", my_num7);
		my_num7++;
	}


	printf("\n\t int64_t\n");
	printf("Biggest 64-bit signed int: %li\n", INT64_MAX);
	printf("Smallest 64-bit signed int: %li\n", INT64_MIN);
	int64_t my_num8 = INT64_MAX - 5;
	while (my_num8 > 0) {
		printf("This is a 64-bit signed int: %li\n", my_num8);
		my_num8++;
	}
	my_num8 = INT64_MIN + 5;
	while (my_num8 < 0) {
		printf("This is a 64-bit unsigned int: %li\n", my_num8);
		my_num8--;
	}

	return 0;
}
