exec = ./bin/JSGen.exe
sources = $(wildcard ./src/*.c)
objects = $(sources:.c=.o)
flags = -g -Wall -O2 -lm -fPIC -export-dynamic

$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

clean:
	rm -rf src/*.o
	clear