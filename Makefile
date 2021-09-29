.PHONY: all
all: password_counter

password_counter: password_counter.c
	gcc -Wall -g password_counter.c -o password_counter

.PHONY: clean
clean:
	rm -f password_counter

