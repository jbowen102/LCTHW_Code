#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// Set up a structure data type to be used later. It has attributes name, age, height, and weight.
struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

// Define a function that creates a person with the attributes assigned to
// values passed to the function as parameters
struct Person *Person_create(char *name, int age, int height, int weight)
{
	// allocate memory of the size needed for a Person structure.
	struct Person *who = malloc(sizeof(struct Person));
	// make sure memory pointer allocated by malloc() isn't bogus.
	assert(who != NULL);

	// directly assign values to the new structure at the "who" pointer.
	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
}

// function to erase the person struct from memory and free the mem for other uses.
void Person_destroy(struct Person *who)
{
	// make sure mem pointer is valid
	assert(who != NULL);

	// free both the string mem ref'd by pointer who->name and the overall struct
	// referenced by the pointer who.
	free(who->name);
	free(who);
}

// print out the attributes of a Person structure.
void Person_print(struct Person *who)
{
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
	// Create two people structures
	struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
	struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

	// Print them out and where they are in memory
	printf("Joe is at memory location %p\n", joe);
	Person_print(joe);

	printf("Frank is at memory location %p\n", frank);
	Person_print(frank);

	// make everyone age 20 years and print them again
	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	frank->age += 20;
	frank->weight += 20;
	Person_print(NULL);

	// Destroy them both so we clean up.
	Person_destroy(joe);
	Person_destroy(frank);

	// Person_destroy(NULL);

	return 0;
}
