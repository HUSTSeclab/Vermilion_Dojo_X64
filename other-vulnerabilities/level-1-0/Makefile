TARGET = format-string-level1.0
CC     = gcc
CFLAGS = -Wall -Wextra  -Wno-format-security -Wno-format-security -Wno-stringop-overflow
SECFLAGS =
INCLUDE = -I ../../include ../../include/util.c

.PHONY: all clean

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $(SECFLAGS) $(INCLUDE) -o $@ $<

clean: 
	rm -rf $(TARGET)
