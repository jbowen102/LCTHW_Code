 #include <stdio.h>

int print_with_array_index(char *names[], int *ages, int count);
int print_with_pointer(char **cur_name, int *cur_age, int count);
int print_with_array_index2(char **cur_name, int *cur_age, int count);
int print_with_pointer2(char **cur_name, char **names, int *cur_age, int *ages, int count);

int main(int argc, char *argv[])
{

	// create two arrays we care about
	int ages[] = { 23, 43, 12, 89, 2 };
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa"
	};

	// safely get the size of ages
	int count = sizeof(ages) / sizeof(int);

  print_with_array_index(names, ages, count);

	printf("---\n");

	// set up the pointers to the start of the arrays
	int *cur_age = ages;
	char **cur_name = names;

  print_with_pointer(cur_name, cur_age, count);

	printf("---\n");

	// Third way, pointers are just arrays.
  print_with_array_index2(cur_name, cur_age, count);

	printf("---\n");

	// Fourth way with pointers in a stupid complex array.
  print_with_pointer2(cur_name, names, cur_age, ages, count);

  int i = 0;
  for (i = 0 ; i < count ; i++) {
    printf("Address of %s stored in names: %p\n", names[i], &(names[i]));
  }

	return 0;
}

int print_with_array_index(char *names[], int *ages, int count)
{
  int i = 0;
  for (i = 0 ; i < count ; i++) {
    printf("%s has %d years alive.\n", names[i], ages[i]);
  }

  return 0;
}

int print_with_pointer(char **cur_name, int *cur_age, int count)
{
  int i = 0;
  for (i = 0 ; i < count ; i++) {
  printf("%s is %d years old.\n",
    *(cur_name + i), *(cur_age + i));
  }
  return 0;
}

int print_with_array_index2(char **cur_name, int *cur_age, int count)
{
  int i = 0;
  for (i = 0 ; i < count ; i++) {
    printf("%s is %d years old again.\n",
      cur_name[i], cur_age[i]);
  }
  return 0;
}

int print_with_pointer2(char **cur_name, char **names, int *cur_age, int *ages, int count)
{
  for (cur_name = names, cur_age = ages ;
    (cur_age - ages) < count ; cur_name++, cur_age++) {
      printf("%s lived for %d years so far.\n", *cur_name, *cur_age);
  }
  return 0;
}
