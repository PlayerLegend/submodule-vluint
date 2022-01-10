#ifndef FLAT_INCLUDES
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define FLAT_INCLUDES
#include "../range/def.h"
#include "../window/def.h"
#include "vluint.h"
#include "../convert/source.h"
#endif

/** @file vluint/source.h
    Provides a function for reading vluints described in vluint/vluint.h from a convert_source described in convert/source.h
 */

unsigned long long vluint_read_source (bool * error, convert_source * source, size_t limit);
/**<
   @brief Reads a vluint from the given source, consuming bytes as it reads.
   @param error Will be set to true if an error occurs
   @param source The source to be read
   @param limit The maximum number of bytes to read while searching for the end of a vluint
   @return The value of the vluint that was read, or -1 if an error occured
*/
