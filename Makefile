#
#
#
#
#
#

CC = gcc
CFLAGS = -O3
LIBSTDC = -l m
LIBOBJC = -l objc
LIBCPP = -l stdc++

all: test-c \
     test-objc \
     test-printf \
     test-mem \
     test-macro \
     test-scanf \
     test-multithread.c

test-multithread: test-multithread.o
	$(CC) $(CFLAGS) $(?) -o $(@) $(LIBOBJC) $(LIBSTDC)

test-multithread.o: test-multithread.c
	$(CC) $(CFLAGS) -c $(?) -o $(@)

test-objc: test-objc.o
	$(CC) $(CFLAGS) $(?) -o $(@) $(LIBOBJC) $(LIBSTDC)

test-objc.o: test-objc.m
	$(CC) $(CFLAGS) -c $(?) -o $(@) 

test-c: test-c.o
	$(CC) $(CFLAGS) $(?) -o $(@) $(LIBSTDC)

test-c.o: test-c.c
	$(CC) $(CFLAGS) -c $(?) -o $(@)

test-printf: test-printf.o
	$(CC) $(CFLAGS) $(?) -o $(@) $(LIBSTDC)

test-printf.o: test-printf.c
	$(CC) $(CFLAGS) -c $(?) -o $(@)

test-mem: test-mem.o
	$(CC) $(CFLAGS) $(?) -o $(@) $(LIBCPP) $(LIBSTDC)

test-mem.o: test-mem.cpp
	$(CC) $(CFLAGS) -c $(?) -o $(@)

test-macro: test-macro.o
	$(CC) $(CFLAGS) $(?) -o $(@) $(LIBSTDC)

test-macro.o: test-macro.c
	$(CC) $(CFLAGS) -c $(?) -o $(@)

test-scanf: test-scanf.o
	$(CC) $(CFLAGS) $(?) -o $(@) $(LIBSTDC)

test-scanf.o: test-scanf.c
	$(CC) $(CFLAGS) -c $(?) -o $(@)

clean:
	rm -rf *.o test-*.exe

cleano:
	rm -rf *.o
