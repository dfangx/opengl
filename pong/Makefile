SHELL = /bin/bash

.SUFFIXES:
.SUFFIXES: .c .o

CC = g++
LDFLAGS = -Iinclude/ -lGL -lglfw -lGLEW

SRC = app.cpp main.cpp pong.cpp resource_manager.cpp shader.cpp vertex_array_object.cpp vertex_buffer.cpp element_buffer.cpp
OBJ = pong
all: 
	$(CC) $(SRC) -o $(OBJ) $(LDFLAGS)
