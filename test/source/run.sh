#!/bin/sh

echo "This should work"
$DEBUG_PROGRAM2 test/vluint-source-output 234892 | $DEBUG_PROGRAM test/vluint-source 3

echo "Done"

