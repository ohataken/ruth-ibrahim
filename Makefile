.c.o:
	$(CC) -Wall -c $<

ruth-ibrahim.o: command.o main.o
	$(CC) -o ruth-ibrahim.o $^

run: ruth-ibrahim.o
	./ruth-ibrahim.o
