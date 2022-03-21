#include "source.h"

bool vluint_read_source (vluint_result * result, convert_source * source, size_t limit)
{
    range_const_unsigned_char * input = &source->contents->region.const_cast;

    status status;

    while (true)
    {
	if (vluint_read (result, input))
	{
	    return true;
	}

	if ((size_t)range_count (*input) >= limit)
	{
	    return false;
	}
	
	if ( (status = convert_grow(source, 32)) != STATUS_UPDATE)
	{
	    return false;
	}
    }
}
