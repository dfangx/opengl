SHELL = /bin/bash

.SUFFIXES:
.SUFFIXES: .c .o

CC = g++
LDFLAGS = -Iinclude/ -lGL -lglfw -lGLEW

SRC = app.cpp main.cpp callback.cpp shader.cpp buffer.cpp vertex_array_object.cpp 
OBJ = simple_window
all: 
	$(CC) $(SRC) -o $(OBJ) $(LDFLAGS)
