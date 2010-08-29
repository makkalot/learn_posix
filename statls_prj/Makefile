CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=statls.c test_statls.c errutils.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=statls

all: $(SOURCES) $(EXECUTABLE)
		
$(EXECUTABLE): $(OBJECTS) 
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
		$(CC) $(CFLAGS) $< -o $@

clean:
	@rm $(EXECUTABLE)
	@rm *.o
