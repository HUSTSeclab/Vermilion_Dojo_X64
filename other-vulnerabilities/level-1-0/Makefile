TARGET = format-string-level1.0
CC     = gcc
CFLAGS = -Wall -Wextra  -Wno-format-security -Wno-format-security -Wno-stringop-overflow
SECFLAGS =

.PHONY: all clean

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $(SECFLAGS) -o $@ $<

clean: 
	rm -rf $(TARGET)
