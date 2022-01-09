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

unsigned long long vluint_read_source (bool * error, convert_source * source, size_t limit);
