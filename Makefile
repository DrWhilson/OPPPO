CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=lab1.cpp figure.h 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=lab

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
