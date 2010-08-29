CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=grpusers.c errutils.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=grpusers

all: $(SOURCES) $(EXECUTABLE)
		
$(EXECUTABLE): $(OBJECTS) 
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
		$(CC) $(CFLAGS) $< -o $@

clean:
	@rm $(EXECUTABLE)
	@rm *.o
