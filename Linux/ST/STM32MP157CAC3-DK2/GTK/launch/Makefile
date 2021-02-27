PROG = main
SRCS = main.c

CLEANFILES = $(PROG)

# Add / change option in CFLAGS and LDFLAGS
CFLAGS += -Wall $(shell pkg-config --cflags --libs gtk+-3.0)
LDFLAGS += $(shell pkg-config --libs gtk+-3.0)

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(CLEANFILES) $(patsubst %.c,%.o, $(SRCS))