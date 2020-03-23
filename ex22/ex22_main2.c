#include "ex22.h"
// #include "ex22.c" // use this only if compiling w/o ex22.o
#include "dbg.h"

const char *MY_NAME = "Zed A. Shaw";

void scope_demo(int count)
{
	// log_info("Count is: %d", count);
	//
	// if (count > 10) {
	// 	int count = 100;		// BAD! BUGS!
	// 	// count = 100;		// This way doesn't create a new var. Assigns to existing.
	//
	// 	log_info("count in this scope is %d", count);
	// }
	//
	// log_info("count at exit is %d", count);
	//
	// count = 3000;
	//
	// log_info("count after assign: %d", count);

	count += 1;
	log_info("Count: %d", count);
	scope_demo(count);
}

int main(int argc, char *argv[])
{
	// test out THE_AGE accessors
	log_info("My name: %s, my age: %d", MY_NAME, get_age());

	set_age(100);

	log_info("My age is now %d", get_age());

	// test out THE_SIZE extern
	log_info("THE_SIZE is %d", THE_SIZE);
	print_size();

	// test the ratio function static
	log_info("Ratio at first: %f", update_ratio(2.0));
	log_info("Ratio again: %f", update_ratio(10.0));
	log_info("Ratio once again: %f", update_ratio(300.0));

	// test the scope demo
	int count = 4;
	scope_demo(count);
	scope_demo(count * 20);

	log_info("count after calling scope_demo: %d", count);

	// log_info("trying to access ratio. Here it is: %f", ratio);

	// log_info("Trying to access THE_AGE directly: %d", THE_AGE)

	return 0;
}
