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
	sh makedepend.sh src/vluint/vluint.makefile

vluint-tests: test/vluint

tests: vluint-tests
# DO NOT DELETE

src/vluint/vluint.o: src/range/def.h src/window/def.h src/window/alloc.h
src/vluint/vluint.o: src/vluint/vluint.h src/log/log.h
src/vluint/test/source/output.o: src/vluint/vluint.h src/range/def.h
src/vluint/test/source/output.o: src/window/def.h src/convert/status.h
src/vluint/test/source/output.o: src/convert/sink.h src/convert/fd/sink.h
src/vluint/test/source/output.o: src/log/log.h
src/vluint/test/source/source.o: src/vluint/source.h src/convert/source.h
src/vluint/test/source/source.o: src/range/def.h src/window/def.h
src/vluint/test/source/source.o: src/convert/status.h src/vluint/vluint.h
src/vluint/test/source/source.o: src/convert/fd/source.h
src/vluint/test/base/test.o: src/vluint/vluint.h src/range/def.h
src/vluint/test/base/test.o: src/window/def.h src/window/printf.h
src/vluint/source.o: src/vluint/source.h src/convert/source.h src/range/def.h
src/vluint/source.o: src/window/def.h src/convert/status.h
src/vluint/source.o: src/vluint/vluint.h
