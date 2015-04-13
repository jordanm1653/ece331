TARGET=i2c
OBJS=i2c.o
CFLAGS=-Wall -g
LDFLAGS=
.PHONY: clean all

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)

clean:
	rm -f $(TARGET) $(OBJS)

