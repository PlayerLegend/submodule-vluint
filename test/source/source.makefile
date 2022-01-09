test/vluint-source: \
	src/vluint/test/source/source.o \
	src/vluint/vluint.o \
	src/vluint/source.o \
	src/window/alloc.o \
	src/convert/source.o \
	src/convert/fd/source.o \
	src/log/log.o

C_PROGRAMS += test/vluint-source

vluint-tests: test/vluint-source

tests: vluint-tests
