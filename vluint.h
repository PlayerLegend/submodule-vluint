#ifndef FLAT_INCLUDES
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define FLAT_INCLUDES
#include "../range/def.h"
#include "../window/def.h"
#endif


void vluint_write (window_unsigned_char * output, unsigned long long input);
unsigned long long vluint_read (bool * error, range_const_unsigned_char * input);
