CFLAGS = -std=c23 -g -Wall -Werror
LDFLAGS = -pthread

%.o:%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

all: 01_create_join 02_input_output 03_mutex
	@echo build complete

01_create_join: 01_create_join.o
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $^

02_input_output: 02_input_output.o
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $^

03_mutex: 03_mutex.o
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o
	rm -f 01_create_join
	rm -f 02_input_output
	rm -f 03_mutex
