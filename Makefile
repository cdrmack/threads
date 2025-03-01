CFLAGS = -std=c23 -g -Wall -Werror
LDFLAGS = -pthread

%.o:%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

all: thread
	@echo build complete

thread: main.o
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o thread main.o

clean:
	rm -f thread main.o
