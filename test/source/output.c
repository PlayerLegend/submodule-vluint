#include "../../vluint.h"
#include "../../../convert/status.h"
#include "../../../convert/sink.h"
#include "../../../convert/fd/sink.h"
#include <unistd.h>
#include "../../../log/log.h"

int main(int argc, char * argv[])
{
    unsigned long long n = argc == 2 ? atoll(argv[1]) : 14578;
    
    window_unsigned_char contents = {0};

    vluint_write (&contents, n);

    fd_sink fd_sink = fd_sink_init (STDOUT_FILENO, &contents.region.const_cast);

    if (convert_drain (&fd_sink.sink) != STATUS_UPDATE)
    {
	log_fatal ("Could not write to output");
    }

    return 0;

fail:
    exit (1);
}
