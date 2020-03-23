CFLAGS=-Wall -g -DNDEBUG

first:
	gcc $(CFLAGS) -c -o ex22.o ex22.c

second:
	gcc $(CFLAGS) ex22_main.c ex22.o -o ex22_main

clean:
	rm -f ex22_main
	rm -f ex22.o
