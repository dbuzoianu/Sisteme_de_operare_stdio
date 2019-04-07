CC=gcc
CFLAGS=-g -Wall
LBFLAG=-fPIC
OBJ=lib.o
TARGET=libso_stdio.so

build: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -shared $(LBFLAG) $(OBJ) -o $(TARGET)

$(OBJ): tema2.c
	$(CC) $(CFLAGS) -c $(LBFLAG) tema2.c -o $(OBJ)

clean:
	rm -f *.o $(TARGET)