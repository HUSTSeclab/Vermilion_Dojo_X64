TARGET = fmt-str-level1.1
CC     = gcc
CFLAGS = -Wall  -Wextra -z lazy -fno-stack-protector -Wno-format-security -Wno-stringop-overflow
INCLUDE = -I ../../include ../../include/util.c

.PHONY: all clean

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $(SECFLAGS) $(INCLUDE) -o $@ $<

clean: 
	rm -rf $(TARGET)
