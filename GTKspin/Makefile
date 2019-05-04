CC = gcc
SRC_DIR = .
INC_DIR = .
OBJ_DIR = .
CFLAGS = -Wall
PACKAGE = `pkg-config --cflags --libs gtk+-2.0`
LIBS = `pkg-config --libs gtk+-2.0`
EXE = gui
 
OBJS = $(OBJ_DIR)/main.o 

all: clean build       

# when linking the final pass only --libs from pkg-config are needed
build: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE) $(LIBS)
	rm -f *.o

# when objects are built both --cflags --libs from pkg-config are needed
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -I$(INC_DIR) $< -o $@ $(PACKAGE)

clean: 
	rm -f *.o $(EXE)
