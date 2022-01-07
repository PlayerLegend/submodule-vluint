#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define FLAT_INCLUDES
#include "../range/def.h"
#include "../window/def.h"
#include "../window/alloc.h"
#include "vluint.h"
#include "../log/log.h"

#define VLUINT_CHAR_MAX 128

unsigned long long vluint_read (bool * error, range_const_unsigned_char * input)
{
    unsigned long long result = 0;
    
    unsigned char c;

    unsigned long long power = 1;
    unsigned char cnum;

    while (true)
    {
	if (range_is_empty (*input))
	{
	    goto fail;
	}
	
	c = *(input->begin++);

	cnum = c & ~VLUINT_CHAR_MAX;

	result += power * cnum;

	if (c == cnum)
	{
	    return result;
	}

	power *= VLUINT_CHAR_MAX;
    }

fail:
    *error = true;
    return -1;
}

void vluint_write (window_unsigned_char * output, unsigned long long input)
{
    //buffer_rewrite (*output);

    while (input >= VLUINT_CHAR_MAX)
    {
	*window_push(*output) = (input % VLUINT_CHAR_MAX) | VLUINT_CHAR_MAX;
	input = input >> 7;

	assert (output->region.end[-1] & VLUINT_CHAR_MAX);
    }

    *window_push(*output) = input;
}
