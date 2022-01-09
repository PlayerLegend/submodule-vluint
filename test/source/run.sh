#!/bin/sh

echo "This should work"
$DEBUG_PROGRAM2 test/vluint-source-output 234892 | $DEBUG_PROGRAM test/vluint-source 3

echo "This should fail"
! test/vluint-source-output 234892 | test/vluint-source 2

echo "Done"

