
all: clean test

clean:
	rm -f getch-test

test:
	$(CC) getch.c test.c -std=c99 -o getch-test
	./getch-test

.PHONY: all clean test
