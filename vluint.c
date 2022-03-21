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

bool vluint_read (vluint_result * result, range_const_unsigned_char * input)
{
    const unsigned char * start = input->begin;
    
    unsigned long long sum = 0;
    
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

	sum += power * cnum;

	if (c == cnum)
	{
	    *result = sum;
	    return true;
	}

	power *= VLUINT_CHAR_MAX;
    }

fail:
    input->begin = start;
    return false;
}

void vluint_write (window_unsigned_char * output, vluint_result input)
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
