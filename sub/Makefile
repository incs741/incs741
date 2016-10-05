default: clean compile

clean:
	@rm -rf gen enc dec *.o *.h.gch *~

compile: crypt-sub.c gen.c cat.c
	gcc -c crypt-sub.c -o crypt-sub.o
	gcc -c gen.c -o gen.o
	gcc -c cat.c -o cat.o
	gcc gen.o crypt-sub.o -o gen
	gcc cat.o crypt-sub.o -o cat

gen: default
	./gen

cat: default
	./cat key.txt
