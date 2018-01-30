CFLAGS = -Wall -fpic -coverage -lm

testme: testme.c
	gcc -o testme testme.c -g $(CFLAGS)
run: testme
	./testme
all: testme run
