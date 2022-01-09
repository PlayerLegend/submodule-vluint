test/vluint-source-output: \
	src/vluint/test/source/output.o \
	src/vluint/vluint.o \
	src/window/alloc.o \
	src/convert/sink.o \
	src/convert/fd/sink.o \
	src/log/log.o

C_PROGRAMS += test/vluint-source-output

vluint-tests: test/vluint-source-output

tests: vluint-tests
