SOURCES = 01_create_join.c 02_input_output.c 03_mutex.c 04_semaphore.c

CFLAGS = -std=c23 -g -Wall -Werror
LDFLAGS = -pthread

# create a target for each source file
TARGETS = $(SOURCES:.c=)

all: $(TARGETS)

%: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)

.PHONY: all clean
