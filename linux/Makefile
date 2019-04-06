CC = gcc
CFLAGS = -g -Wall
LBFLAGS = fPIC
OBJ = lib.o
TARGET = libso_stdio.so

build: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -shared $(LBFLAGS) $(OBJ) -o $(TARGET)


$(OBJ): tema2.c 
	$(CC) $(CFLAGS) -c $(LBFLAGS) tema2.c -o $(TARGET)

clean:
	rm -f *.o $(TARGET)