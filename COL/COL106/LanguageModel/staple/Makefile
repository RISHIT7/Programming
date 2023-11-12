CC = gcc
CFLAGS = -c -std=c99 -g
LDFLAGS = -g
SRC = ${wildcard src/*.c}
HDR = ${wildcard include/*.h}
OBJ = ${SRC:.c=.o}
EXEC = staple

all: ${SRC} ${OBJ} ${EXEC}

debug: all
debug: CFLAGS += -DEBUG

${EXEC}: ${OBJ}
	${CC} ${LDFLAGS} $^ -o $@

%.o: %.c ${HDR}
	${CC} ${CFLAGS} $< -o $@

clean:
	rm -f src/*.o ${EXEC}

compile: all
compile:
	./staple compile test/first.stvm