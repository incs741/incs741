default: clean compile

clean:
	@rm -rf gen enc dec *.o *.h.gch *~

compile: gen.c
	gcc -c gen.c -o gen.o
	gcc -c crypt-sub.c -o crypt-sub.o
	gcc gen.o crypt-sub.o -o gen

test: default
	./gen
