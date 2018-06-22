CC=gcc

ODIR=obj
IDIR=include
SDIR=src

IFLAGS=-I$(IDIR)
CFLAGS=-Wall

_DEPS = stack.h queue.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o stack.o queue.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(IFLAGS)

data-struct-sample: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f obj/*.o

.PHONY: clean-all

clean-all:
	rm -f obj/*.o && rm -f data-struct-sample