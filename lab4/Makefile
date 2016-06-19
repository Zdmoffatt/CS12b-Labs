#Zachary Moffatt
#zmoffatt
#5/1/16
#CS12m
#Lab4
#Makefile
#Makefile for charType.c

FLAGS = -std=c99 -Wall
SOURCES = charType.c README Makefile 
OBJECTS = charType.o
EXEBIN = charType

all: $(EXEBIN)
$(EXEBIN): $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS): $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

clean:
	rm -f $(EXEBIN) $(OBJECTS)

submit: $(SOURCES)
	submit cmps012b-pt.s16 lab4 $(SOURCES)

check: 
	ls  /afs/cats.ucsc.edu/class/cmps012b-pt.s16/lab4/zmoffatt

