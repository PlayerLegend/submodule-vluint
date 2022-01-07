#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FLAT_INCLUDES
#include "../../range/def.h"
#include "../../window/def.h"
#include "../../window/printf.h"
#include "../vluint.h"
//#include "../../metabase/metabase.h"
#include "../../log/log.h"

int main(int argc, char * argv[])
{
    unsigned long long n = argc == 2 ? atoll(argv[1]) : 14578;

    window_unsigned_char input = {0};
    
    vluint_write(&input, n);
    window_printf_append((window_char*) &input,"asdf");

    size_t start_size = range_count(input.region);
    
    bool error = false;
    unsigned long long result = vluint_read (&error, &input.region.const_cast);
    assert (!error);

    assert (range_count(input.region) == 4);
    assert (0 == memcmp (input.region.begin, "asdf", 4));

    printf("test int: %llu\n", result);
    printf ("length: %zu\n", start_size - range_count(input.region));

    assert (result == n);

    return 0;
}
