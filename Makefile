CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = wordcount

$(TARGET): wordcounting.c
	$(CC) $(CFLAGS) -o $(TARGET) wordcounting.c

.PHONY: clean
clean:
	rm -f $(TARGET)

