CC = gcc
CL = ld

CFLAGS = -std=c99 \
		 -I. \
		 -g \
		 -lssl \
		 -lcrypto \
		 -lpthread \
		 -lm

CEBSOCKET_SOURCES = $(filter-out $(shell find ../../ -path "*/examples/*"), $(shell find ../../ -name "*.c"))
CEBSOCKET_HEADERS = $(filter-out $(shell find ../../ -path "*/examples/*"), $(shell find ../../ -name "*.h"))
CEBSOCKET_OBJ = ../websocket.o
SOURCE = main.c
EXECUTABLE = $(SOURCE:.c=)

.PHONY: clean cebsocket

all: $(EXECUTABLE)

cebsocket:
	make -C ..

clean:
	$(RM) $(EXECUTABLE)

$(EXECUTABLE): cebsocket $(CEBSOCKET_OBJ)
	$(CC) -o $@ $(SOURCE) $(CEBSOCKET_OBJ) $(CFLAGS)