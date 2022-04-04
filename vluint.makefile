test/vluint: \
	src/vluint/test/base/test.o \
	src/vluint/vluint.o \
	src/window/printf.o \
	src/window/printf_append.o \
	src/window/alloc.o \
	src/window/vprintf.o \
	src/window/vprintf_append.o


C_PROGRAMS += test/vluint
run-tests: run-vluint-tests
run-vluint-tests:
	DEPENDS=vluint-tests sh run-tests.sh test/vluint

depend: vluint-depend
vluint-depend:
	cdeps src/vluint > src/vluint/depends.makefile

vluint-tests: test/vluint

tests: vluint-tests
