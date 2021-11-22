CC=gcc
CFLAGS=-lm
DEPS = imageFormationUtils.h
OBJ = imageFormationUtils.o  imageFormation.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

imageFormation: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)