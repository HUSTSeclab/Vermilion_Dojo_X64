TARGET = buffer-overflow-level4.0
CC     = gcc
CFLAGS = -Wall -Wextra
SECFLAGS = -fno-stack-protector -no-pie

.PHONY: all clean

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $(SECFLAGS) -o $@ $<

clean: 
	rm -rf $(TARGET)