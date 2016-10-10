#author  : Rajan Khullar
#created : 10/04/16
#updated : 10/10/16

CC      = gcc
BINS    = enc dec
DEPS    = support.h
OBJS    = support.o
CFLAGS  =

SFX     = exe
EXES    = $(addsuffix .$(SFX), $(BINS))

default: clean compile

clean:
	@rm -rf $(BINS) *.$(SFX) *.o *.h.gch *~ *.txt *.dat

%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS) -o $@

%.$(SFX): %.o $(OBJS)
	$(CC) $^ $(CFLAGS) -o $@
	@mv $@ $(@:.$(SFX)=)

compile: $(EXES)

enc.o: target.c $(DEPS)
	$(CC) -c $< -D mode=1 -o $@

dec.o: target.c $(DEPS)
	$(CC) -c $< -D mode=2 -o $@
