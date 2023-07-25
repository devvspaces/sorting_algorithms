
CFLAGS = -Wall -Wextra -Werror -pedantic  -std=gnu89
TARGET = test

all:
	betty *.c *.h
	gcc $(CFLAGS) *.c  tests/$(TARGET) -o main 
