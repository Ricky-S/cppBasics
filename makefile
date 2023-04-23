CC = g++
CFLAGS = -Wall -g
  
  # build an executable named myprog from myprog.c
demo: c1.cpp add.cpp
	${CC} ${CFLAGS} -I./ -o demo c1.cpp add.cpp

  clean: 
	$(RM) demo