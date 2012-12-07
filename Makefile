CFLAGS= -Wall -g

all: myanimals

myanimals: animal.o

clean:
	rm -f *~ *.o myanimals 