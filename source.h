#ifndef FLAT_INCLUDES
#include "../convert/source.h"
#include "vluint.h"
#endif

/** @file vluint/source.h
    Provides a function for reading vluints described in vluint/vluint.h from a convert_source described in convert/source.h
 */

bool vluint_read_source (vluint_result * result, convert_source * source, size_t limit);
/**<
   @brief Reads a vluint from the given source, consuming bytes as it reads.
   @param result The resulting integer
   @param source The source to be read
   @param limit The maximum number of bytes to read while searching for the end of a vluint
   @return True on success, false otherwise
*/
