#include "../../vluint.h"
#include "../../../window/printf.h"
#include <assert.h>
#include <string.h>

int main(int argc, char * argv[])
{
    unsigned long long n = argc == 2 ? atoll(argv[1]) : 14578;

    window_unsigned_char input = {0};
    
    vluint_write(&input, n);
    window_printf_append((window_char*) &input,"asdf");

    size_t start_size = range_count(input.region);
    
    vluint_result result;

    assert (vluint_read (&result, &input.region.const_cast));

    assert (range_count(input.region) == 4);
    assert (0 == memcmp (input.region.begin, "asdf", 4));

    printf("test int: %llu\n", result);
    printf ("length: %zu\n", start_size - range_count(input.region));

    assert (result == n);

    return 0;
}
