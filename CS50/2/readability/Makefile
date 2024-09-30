# Define the compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -std=c99 -g

# Define a variable for source files and object files
SOURCES = $(wildcard *.c)
EXECUTABLES = $(SOURCES:.c=)

# Rule to build all executables
all: $(EXECUTABLES)

# Rule to build each executable
%: %.c
	$(CC) $(CFLAGS) -o $@ $< -lcs50

# Rule to clean up compiled files
clean:
	rm -f $(EXECUTABLES)
