CC=gcc
SOURCES=src/*.c
INCLUDES= 
LIBS= `pkg-config --libs gtk+-3.0 webkit2gtk-4.0`
CFLAGS= -o $(OUTPUT) -Wall -g  `pkg-config --cflags gtk+-3.0 webkit2gtk-4.0`
OUTPUT=bin/webview

all: clean build

build:
	mkdir -p bin/
	$(CC) $(CFLAGS) $(INCLUDES) $(SOURCES) $(LIBS)

clean:
	rm -rf bin/
