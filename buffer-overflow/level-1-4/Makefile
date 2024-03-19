TARGET = buffer-overflow-level1.4
CC     = gcc
CFLAGS = -Wall -Wextra
SECFLAGS = -fno-stack-protector
INCLUDE = -I ../../include ../../include/util.c

.PHONY: all clean

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $(SECFLAGS) $(INCLUDE) -o $@ $<

clean: 
	rm -rf $(TARGET)
