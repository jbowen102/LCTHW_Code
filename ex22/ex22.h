#ifndef _ex22_h
#define _ex22_h

// makes THE_SIZE in ex22.c available to other .c files
// extern int THE_SIZE;
int THE_SIZE;  // this works too. Only needed at all because of how the book compiles.
                  // compiling in one shot doesn't require it.

// gets and sets an internal static variable in ex22.c
int get_age();

void set_age(int age);

// updates a static ratio that's inside update_ratio

double update_ratio(double ratio);

void print_size();

#endif
