# makefile for bcmrgb.c
#
TARGET=bcmrgb
CFLAGS=-g -Wall
OBJS=bcmrgb.o
LDFLAGS=-lbcm2835

.PHONY: clean all

#all: ${TARGET}

${TARGET}: ${OBJS}
	${CC} -o ${TARGET} ${OBJS} ${LDFLAGS} 

clean:
	rm -f ${TARGET} ${OBJS}
