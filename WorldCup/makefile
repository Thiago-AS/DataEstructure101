HEADERS = cup.h list.h tree.h
OBJECTS = cup.o list.o tree.o main.o

%.o: %.c $(HEADERS)
	gcc -c $< -o $@

World_Cup: $(OBJECTS)
	gcc $(OBJECTS) -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f World_Cup
