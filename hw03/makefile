TARGET=swa
OBJS=swa.o
CFLAGS=-Wall -g
.PHONY: clean all

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

clean:
	rm -f $(TARGET) $(OBJS)

