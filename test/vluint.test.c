#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FLAT_INCLUDES
#include "../../keyargs/keyargs.h"
#include "../../array/range.h"
#include "../../window/def.h"
#include "../../window/printf.h"
#include "../vluint.h"
#include "../../metabase/metabase.h"
#include "../../log/log.h"

int main(int argc, char * argv[])
{
    vluint_result n = argc == 2 ? atoll(argv[1]) : 14578;

    window_unsigned_char input = {0};
    
    vluint_write(&input, n);
    window_printf_append((window_char*) &input,"asdf");
    
    range_const_unsigned_char vluint = {0};
    vluint_result result = 0;
    range_const_unsigned_char rest = {0};

    assert (vluint_read (.result = &result, .vluint = &vluint, .rest = &rest, .input = &input.region.const_cast));

    assert (vluint.begin < vluint.end);
    assert (range_count(rest) == 4);

    assert (0 == memcmp (rest.begin, "asdf", 4));
    
    printf("test int: %zu\n", result);
    printf ("length: %zu\n", range_count(vluint));
    window_char encode = {0};

    metabase_encode_base16(&encode, &vluint);

    printf("hex: %.*s", (int)range_count(encode.region), encode.region.begin);

    assert (result == n);

    return 0;
}
