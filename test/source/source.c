#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define FLAT_INCLUDES
#include "../../../range/def.h"
#include "../../../window/def.h"
#include "../../../convert/source.h"
#include "../../../convert/fd/source.h"
#include "../../source.h"

int main(int argc, char * argv[])
{
    assert (argc == 2);
    
    window_unsigned_char contents = {0};
    fd_source fd_source = fd_source_init (STDIN_FILENO, &contents);

    bool error = false;
    
    unsigned long long result = vluint_read_source(&error, &fd_source.source, atoi(argv[1]));

    if (error)
    {
	printf ("An error occurred\n");
	return 1;
    }

    printf("%llu\n", result);

    return 0;
}
