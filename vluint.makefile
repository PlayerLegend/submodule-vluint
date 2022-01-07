test/vluint: \
	src/vluint/test/test.o \
	src/vluint/vluint.o \
	src/window/printf.o \
	src/window/printf_append.o \
	src/window/alloc.o \
	src/window/vprintf.o \
	src/window/vprintf_append.o


C_PROGRAMS += test/vluint
RUN_TESTS += test/vluint

vluint-tests: test/vluint

tests: vluint-tests

