test/run-vluint-source: src/vluint/test/source/run.sh

SH_PROGRAMS += test/run-vluint-source

vluint-tests: test/run-vluint-source
tests: vluint-tests

RUN_TESTS += test/run-vluint-source
