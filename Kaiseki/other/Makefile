CC = gcc

SOURCES = main.c	\
	  ReadMesh.c	\
	  ReadCond.c	\
	  CalcElem.c	\
	  CalcMatrix.c	\
	  CalcBand.c	\
	  SetBound.c	\
	  Coef.c	\
	  Gauss.c

OBJECTS =$(SOURCES:.c=.o)
TARGET  =fem2d


$(TARGET):	$(OBJECTS)
		$(CC) -o $@ $(OBJECTS)

.c.o:
		$(CC) -c -Wall $< -o $@

clean:
		rm *.o *~ $(TARGET) -rf
