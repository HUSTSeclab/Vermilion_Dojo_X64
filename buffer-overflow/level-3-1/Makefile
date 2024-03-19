TARGET = buffer-overflow-level3.1
CC     = gcc
CFLAGS = -Wall -Wextra -Werror 
SECFLAGS = -no-pie -fno-stack-protector
INCLUDE = -I ../../include ../../include/util.c

.PHONY: all clean

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $(SECFLAGS) $(INCLUDE) -o $@ $<

clean: 
	rm -rf $(TARGET)
