NAME=sudoku_solver
OUTPUT_DIR=output
CPPFLAGS= -std=c++14 -Wall -Wpedantic -Werror 
DEBUGFLAGS?=

default: run

.PHONY: clean run build setup

setup:
	@meson setup ${OUTPUT_DIR}

build:
	@meson compile -C ${OUTPUT_DIR}

run: build
	@${OUTPUT_DIR}/${NAME}

clean:
	@ninja clean -C ${OUTPUT_DIR}

