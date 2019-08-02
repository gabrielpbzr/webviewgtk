CC=gcc
SOURCES=src/*.c
INCLUDES= 
LIBS= `pkg-config --libs gtk+-2.0`
CFLAGS= -o $(OUTPUT) -Wall -g  `pkg-config --cflags gtk+-2.0`
OUTPUT=bin/webview

all: clean build

build:
	mkdir -p bin/
	$(CC) $(CFLAGS) $(INCLUDES) $(SOURCES) $(LIBS)

clean:
	rm -rf bin/
