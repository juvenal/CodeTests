#
#
#
#
#
#

CC = gcc
CFLAGS = -O3
LIBOBJC = -l objc
LIBCPP = -l stdc++

all: test-c \
     test-objc \
     test-printf \
     test-mem \
     test-macro \
     test-scanf

test-objc: test-objc.o
	$(CC) $(CFLAGS) $(?) -o $(@) $(LIBOBJC)

test-objc.o: test-objc.m
	$(CC) $(CFLAGS) -c $(?) -o $(@) 

test-c: test-c.o
	$(CC) $(CFLAGS) $(?) -o $(@)

test-c.o: test-c.c
	$(CC) $(CFLAGS) -c $(?) -o $(@)

test-printf: test-printf.o
	$(CC) $(CFLAGS) $(?) -o $(@)

test-printf.o: test-printf.c
	$(CC) $(CFLAGS) -c $(?) -o $(@)

test-mem: test-mem.o
	$(CC) $(CFLAGS) $(?) -o $(@) $(LIBCPP)

test-mem.o: test-mem.cpp
	$(CC) $(CFLAGS) -c $(?) -o $(@)

test-macro: test-macro.o
	$(CC) $(CFLAGS) $(?) -o $(@)

test-macro.o: test-macro.c
	$(CC) $(CFLAGS) -c $(?) -o $(@)

test-scanf: test-scanf.o
	$(CC) $(CFLAGS) $(?) -o $(@)

test-scanf.o: test-scanf.c
	$(CC) $(CFLAGS) -c $(?) -o $(@)

clean:
	rm -rf *.o test-*.exe

cleano:
	rm -rf *.o
