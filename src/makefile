CC=gcc
INCF=../include
OBJF=./obj

_DEPS= board.h
DEPS=$(patsubst %,$(INCF)/%,$(_DEPS))

_OBJS= minesweeper.o initializeboard.o helper.o displayboard.o changeboard.o
OBJS=$(patsubst %,$(OBJF)/%,$(_OBJS))

$(OBJF)/%.o : %.c $(DEPS)
	$(CC) -o $@ -c $<

minesweeper : ${OBJS}
	$(CC) -o $@ $^

.PHONY : clean

clean: 
	rm -f ${OBJS} $~ $(INCF)/*~
