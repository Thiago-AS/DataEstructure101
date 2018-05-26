HEADERS = expression.h stack.h user.h
OBJECTS = expression.o stack.o user.o main.o

%.o: %.c $(HEADERS)
	gcc -c $< -o $@

Calculadora: $(OBJECTS)
	gcc -std=c99 -lm $(OBJECTS) -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f Calculadora
