#author  : Rajan Khullar
#created : 10/06/16
#updated : 10/06/16

CC      = gcc
BINS    = gen enc dec cat test
DEPS    = crypt-sub.h macros.h
OBJS    = crypt-sub.o
CFLAGS  =

SFX     = exe
EXES    = $(addsuffix .$(SFX), $(BINS))

default: clean compile

clean:
	@rm -rf $(BINS) *.$(SFX) *.o *.h.gch *~ *.txt

%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS) -o $@

%.$(SFX): %.o $(OBJS)
	$(CC) $^ $(CFLAGS) -o $@
	@mv $@ $(@:.$(SFX)=)

compile: $(EXES)
