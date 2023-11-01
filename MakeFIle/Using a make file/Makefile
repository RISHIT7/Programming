# -*- MakeFile -*- 

all: geom tip

geom: geom.o gd.o
	gcc geom.o gd.o -o geom -l m

geom.o: geom.c gd.h
	gcc geom.c -c

gd.o: gd.c 
	gcc gd.c -c

tip: tip.o gd.o
	gcc tip.o gd.o -o tip

tip.o: tip.c gd.h
	gcc tip.c -c
