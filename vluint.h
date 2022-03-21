#ifndef FLAT_INCLUDES
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define FLAT_INCLUDES
#include "../range/def.h"
#include "../window/def.h"
#endif

typedef unsigned long long int vluint_result;

/**
   @file vluint/vluint.h
   Provides functions for reading and writing arbitrary length unsigned integers (very-long-unsigned-integer or vluint). These integers store 7 bits per byte, so this format can be space efficient for small numbers.
*/

void vluint_write (window_unsigned_char * output, vluint_result input);
/**<
   @brief This function appends an integer as a vluint to the window.
   @param output The window to append the integer to.
   @param input The integer to store
*/

bool vluint_read (vluint_result * result, range_const_unsigned_char * input);
/**<
   @brief This function reads a vluint from the given range, consuming the bytes that it reads. On error, no bytes are consumed.
   @param error Will be set to true if an error occurs
   @param input The input range to be read
   @return The value of the integer read, or -1 if an error occurred
*/
