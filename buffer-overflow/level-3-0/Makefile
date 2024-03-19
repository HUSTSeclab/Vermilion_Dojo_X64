TARGET = buffer-overflow-level3.0
CC     = gcc
CFLAGS = -Wall -Wextra
SECFLAGS = -no-pie -fno-stack-protector
INCLUDE = -I ../../include ../../include/util.c

.PHONY: all clean

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $(SECFLAGS) $(INCLUDE) -o $@ $< -lcrypto

clean: 
	rm -rf $(TARGET)
