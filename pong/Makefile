SHELL = /bin/bash

.SUFFIXES:
.SUFFIXES: .c .o

CC = g++
LDFLAGS = -Iinclude/ -lGL -lglfw -lGLEW

SRC = app.cpp main.cpp pong.cpp resource_manager.cpp shader.cpp
OBJ = pong
all: 
	$(CC) $(SRC) -o $(OBJ) $(LDFLAGS)
