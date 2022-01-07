C_PROGRAMS += test/vluint
RUN_TESTS += test/vluint

vluint-tests: test/vluint

test/vluint: src/window/alloc.o
test/vluint: src/window/printf_append.o
test/vluint: src/base16/base16.o
test/vluint: src/base2/base2.o
test/vluint: src/log/log.o
test/vluint: src/log/log.o
test/vluint: src/metabase/metabase.o
test/vluint: src/vluint/test/vluint.test.o
test/vluint: src/vluint/vluint.o

tests: vluint-tests

