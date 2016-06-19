#Zachary Moffatt
#zmoffatt
#4/14/16
#CS12m
#Lab3
#Makefile

FLAGS = -std=c99 -Wall
SOURCES = stringReverse.c README Makefile 
OBJECTS = stringReverse.o
EXEBIN = stringReverse

all: $(EXEBIN)
$(EXEBIN): $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS): $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

clean:
	rm -f $(EXEBIN) $(OBJECTS)

submit: $(SOURCES)
	submit cmps012b-pt.s16 lab3 $(SOURCES)

check: 
	ls  /afs/cats.ucsc.edu/class/cmps012b-pt.s16/lab3/zmoffatt

