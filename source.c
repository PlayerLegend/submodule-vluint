#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define FLAT_INCLUDES
#include "../range/def.h"
#include "../window/def.h"
#include "vluint.h"
#include "../convert/source.h"
#include "source.h"

unsigned long long vluint_read_source (bool * error, convert_source * source, size_t limit)
{
    if (*error)
    {
	return -1;
    }

    unsigned long long retval = -1;
    
    range_const_unsigned_char * input = &source->contents->region.const_cast;

    size_t size = range_count (*input);
    
    do {
	*error = false;

	retval = vluint_read (error, input);

	if (!*error)
	{
	    return retval;
	}

	*error = false;

	size++;

	if (!convert_fill_minimum(error, source, size))
	{
	    goto fail;
	}
    }
    while (size <= limit);

fail:
    *error = true;
    return -1;
}
