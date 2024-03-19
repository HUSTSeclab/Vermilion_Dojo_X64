TARGET = buffer-overflow-level4.0
CC     = gcc
CFLAGS = -Wall -Wextra
SECFLAGS = -fno-stack-protector -no-pie
INCLUDE = -I ../../include ../../include/util.c

.PHONY: all clean

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $(SECFLAGS) $(INCLUDE) -o $@ $<

clean: 
	rm -rf $(TARGET)