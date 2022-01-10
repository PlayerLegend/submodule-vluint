#ifndef FLAT_INCLUDES
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define FLAT_INCLUDES
#include "../range/def.h"
#include "../window/def.h"
#endif

/**
   @file vluint/vluint.h
   Provides functions for reading and writing arbitrary length unsigned integers (very-long-unsigned-integer or vluint). These integers store 7 bits per byte, so this format can be space efficient for small numbers.
*/

void vluint_write (window_unsigned_char * output, unsigned long long input);
/**<
   @brief This function appends an integer as a vluint to the window.
   @param output The window to append the integer to.
   @param input The integer to store
*/

unsigned long long vluint_read (bool * error, range_const_unsigned_char * input);
/**<
   @brief This function reads a vluint from the given range, consuming the bytes that it reads.
   @param error Will be set to true if an error occurs
   @param input The input range to be read
   @return The value of the integer read, or -1 if an error occurred
*/
