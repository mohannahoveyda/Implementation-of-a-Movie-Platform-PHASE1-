CC = g++ --std=c++11

all: a.out

a.out: main.o film.o   netflix.o user.o publisher.o comment.o reply.o dastoor.o functions.o
	${CC} main.o film.o netflix.o user.o publisher.o comment.o reply.o dastoor.o functions.o

main.o: main.cpp film.h netflix.h user.h publisher.h comment.h reply.h dastoor.h functions.h
	${CC} -c main.cpp

film.o: film.cpp film.h publisher.h comment.h user.h
	${CC} -c film.cpp

netflix.o: netflix.cpp netflix.h film.h user.h publisher.h comment.h reply.h dastoor.h functions.h
	${CC} -c netflix.cpp

user.o: user.cpp user.h film.h 
	${CC} -c user.cpp

publisher.o: publisher.cpp publisher.h film.h user.h 
	${CC} -c publisher.cpp


comment.o: comment.cpp comment.h film.h
	${CC} -c comment.cpp

reply.o: reply.cpp reply.h 
	${CC} -c reply.cpp

dastoor.o: dastoor.cpp dastoor.h 
	${CC} -c dastoor.cpp

functions.o: functions.cpp functions.h 
	${CC} -c functions.cpp



.PHONY: clean
clean:
	rm *.o 
	rm a.out
