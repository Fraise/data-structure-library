CC=gcc

ODIR=obj
IDIR=headers
SDIR=src

IFLAGS=-Iheaders
CFLAGS=-Wall
DEPS=stack.h

_DEPS = stack.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o stack.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(IFLAGS)

data-struct-test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f obj/*.o