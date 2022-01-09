#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define FLAT_INCLUDES
#include "../../../range/def.h"
#include "../../../window/def.h"
#include "../../../convert/sink.h"
#include "../../../convert/fd/sink.h"
#include "../../../log/log.h"
#include "../../vluint.h"

int main(int argc, char * argv[])
{
    unsigned long long n = argc == 2 ? atoll(argv[1]) : 14578;
    
    window_unsigned_char contents = {0};

    vluint_write (&contents, n);

    fd_sink fd_sink = fd_sink_init (STDOUT_FILENO, &contents.region.const_cast);

    bool error = false;

    if (!convert_drain (&error, &fd_sink.sink))
    {
	log_fatal ("Could not write to output");
    }

    return 0;

fail:
    exit (1);
}
