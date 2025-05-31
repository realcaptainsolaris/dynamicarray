CC = gcc
TARGET = app
SRC = main.c int_array.c
OBJ = $(SRC:.c=.o)

# Standard: Release
CFLAGS ?= -std=c11 -Wall -Wextra -O2

.PHONY: all clean debug release

all: release

release: CFLAGS += -DNDEBUG
release: $(TARGET)

debug: clean
	$(MAKE) CFLAGS="-std=c11 -Wall -Wextra -O0 -g" $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
