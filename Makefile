CC = g++

CFLAGS = -Iinclude -Wall -Wextra

TARGET = ngl

SRCS = src/main.cpp src/ngl.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ -lcurl

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(TARGET)

install: $(TARGET)
	install -Dm755 $(TARGET) /usr/local/bin/$(TARGET)

uninstall:
	rm -f /usr/local/bin/$(TARGET)

help:
	@echo "Available commands:"
	@echo "  make         - compile everything"
	@echo "  make clean   - delete object files, etc. "
	@echo "  make help    - shows this message"
	@echo "  make install - install NGL spammer"

.PHONY: all clean help install uninstall