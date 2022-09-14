NAME=sudoku_solver
OUTDIR=output
SRCDIR=src
CPPFLAGS= -std=c++14 -Wall -Wpedantic -Werror 
DEBUGFLAGS?=
CPP=g++

default: run

.PHONY: clean

board.o: ${SRCDIR}/board.cpp ${SRCDIR}/board.hpp
	${CPP} -o ${OUTDIR}/board.o ${CPPFLAGS} -c ${SRCDIR}/board.cpp ${DEBUGFLAGS}

main.o: ${SRCDIR}/main.cpp
	${CPP} -o ${OUTDIR}/main.o ${CPPFLAGS} -c ${SRCDIR}/main.cpp ${DEBUGFLAGS}

${NAME}: main.o board.o
	${CPP} -o ${OUTDIR}/${NAME} ${CPPFLAGS} ${OUTDIR}/main.o ${OUTDIR}/board.o ${DEBUGFLAGS}

run: ${NAME}
	@echo
	@${OUTDIR}/${NAME}

clean:
	@rm -f ${OUTDIR}/*.o
	@rm -f ${OUTDIR}/${NAME}
